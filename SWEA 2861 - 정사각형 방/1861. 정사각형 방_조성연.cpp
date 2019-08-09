#include <iostream>

using namespace std;

int field[1000][1000];
int max_cnt;
int num;
bool start;

void Count_Move(int cnt, int N, int x, int y, int start_num);

int main(void)
{
	int T, N;

	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		start = true;
		max_cnt = 0;
		cin >> N;
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> field[i][j];
		Count_Move(1, N, 0, 0, 0);
		cout << '#' << t + 1 << ' ' << num << ' ' << max_cnt << endl;
	}
	return 0;
}

void Count_Move(int cnt, int N, int x, int y, int start_num)
{
	if (start == true)
	{
		start = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (i - 1 >= 0 && field[i][j] + 1 == field[i - 1][j])
					Count_Move(cnt + 1, N, i - 1, j, field[i][j]);
				if (i + 1 < N && field[i][j] + 1 == field[i + 1][j])
					Count_Move(cnt + 1, N, i + 1, j, field[i][j]);
				if (j - 1 >= 0 && field[i][j] + 1 == field[i][j - 1])
					Count_Move(cnt + 1, N, i, j - 1, field[i][j]);
				if (j + 1 < N && field[i][j] + 1 == field[i][j + 1])
					Count_Move(cnt + 1, N, i, j + 1, field[i][j]);
			}
	}
	else
	{
		if (x - 1 >= 0 && field[x][y] + 1 == field[x - 1][y])
			Count_Move(cnt + 1, N, x - 1, y, start_num);
		if (x + 1 < N && field[x][y] + 1 == field[x + 1][y])
			Count_Move(cnt + 1, N, x + 1, y, start_num);
		if (y - 1 >= 0 && field[x][y] + 1 == field[x][y - 1])
			Count_Move(cnt + 1, N, x, y - 1, start_num);
		if (y + 1 < N && field[x][y] + 1 == field[x][y + 1])
			Count_Move(cnt + 1, N, x, y + 1, start_num);
	}

	if (max_cnt < cnt)
	{
		max_cnt = cnt;
		num = start_num;
	}
	else if (max_cnt == cnt && num > start_num)
	{
		max_cnt = cnt;
		num = start_num;
	}
}