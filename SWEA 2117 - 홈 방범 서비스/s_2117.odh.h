#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int map[21][21];
bool check[21][21];
int n, m,result,ans;

void bfs(int y, int x)
{
	memset(check, 0, sizeof(check));
	queue <pair<int, int>> q;
	q.push({ y,x });
	check[y][x] = true;
	int housecnt = 0;
	int cost,qsize;
	result = 0;
	if (map[y][x] == 1)
		housecnt++;
	for (int k = 1; k<=n+1;k++)
	{
		cost = k * k + (k - 1) * (k - 1);
		qsize = q.size();

		if (housecnt * m >= cost)
			result = housecnt;
		
		for (int i = 0; i < qsize; i++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];

				if (ny<1 || nx<1 || ny>n || nx>n)
					continue;
				if (check[ny][nx])
					continue;
				if (map[ny][nx] == 1)
					housecnt++;
				check[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
		
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
			}
		}
		ans = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				bfs(i, j);
				if (result > ans)
					ans = result;
			}
		}
		printf("#%d %d\n",t, ans);
	}
	return 0;
}