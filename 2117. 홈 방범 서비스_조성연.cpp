#include <iostream>
#include <queue>

#define SIZE 20

using namespace std;

int field[SIZE][SIZE];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int N, M;
int Max_Profit;
int Max_Num;

void Find_Max_Area(int x, int y);
int bfs(bool visited[][SIZE]);

queue<pair<int, int>> q;

int main(void)
{
	int T;

	//freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		Max_Profit = 0;
		Max_Num = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> field[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				Find_Max_Area(i, j);
				while (!q.empty())
					q.pop();
			}
		cout << '#' << t + 1 << ' ' << Max_Num << endl;
	}
	return 0;
}
void Find_Max_Area(int x, int y)
{
	bool visited[SIZE][SIZE] = { 0 };
	int cost = 1;
	int profit;
	int num_home = 0;

	q.push({ x, y });
	if (field[x][y])
		num_home++;
	visited[x][y] = true;
	profit = M * num_home - cost;
	if (profit >= 0)
	{
		if (Max_Num < num_home)
			Max_Num = num_home;
	}
	for (int k = 2; k <= N + 1; k++)
	{
		cost = k * k + (k - 1) * (k - 1);
		num_home += bfs(visited);
		profit = M * num_home - cost;
		if (profit >= 0)
		{
			if(Max_Num < num_home)
				Max_Num = num_home;
		}
	}
}

int bfs(bool visited[][SIZE])
{
	int qsize = q.size();
	int cnt = 0;

	for (int i = 0; i < qsize; i++)
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
				if (field[nx][ny])
					cnt++;
			}
		}
	}
	return cnt;
}