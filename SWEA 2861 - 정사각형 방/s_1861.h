#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int map[MAX][MAX],dp[MAX][MAX];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int n;

void dfs(int y, int x)
{
	dp[y][x] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<1 || nx<1 || ny>n || nx>n)
			continue;
		if (map[ny][nx] == 0)
			continue;
		if (map[ny][nx] == map[y][x] + 1)
		{
			if (dp[ny][nx] == 0)
				dfs(ny, nx);
			dp[y][x] = max(dp[y][x], dp[ny][nx] + 1);
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				dp[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dp[i][j] == 0)
					dfs(i, j);
			}
		}
		int ans =0, minv = 987654321;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dp[i][j] > ans)
				{
					ans = dp[i][j];
					minv = map[i][j];
				}
				else if (dp[i][j] == ans)
				{
					minv = min(minv, map[i][j]);
				}
			}
		}

		printf("#%d %d %d\n", t, minv, ans);
	}

	return 0;
}