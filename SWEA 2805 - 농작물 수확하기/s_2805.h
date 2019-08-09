#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n;
int map[50][50];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
bool check[50][50];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		queue <pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf(" %1d", &map[i][j]);

				if (i == (n / 2) && j == (n / 2))
				{
					q.push({ i, j });
					check[i][j] = true;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n / 2 + 1; i++)
		{
			int qsize = q.size();

			for (int j = 0; j < qsize; j++)
			{
				int cy = q.front().first;
				int cx = q.front().second;
				q.pop();
				ans += map[cy][cx];

				for (int k = 0; k < 4; k++)
				{
					int ny = cy + dy[k];
					int nx = cx + dx[k];

					if (ny < 0 || nx < 0 || ny >= n || nx >= n)
						continue;
					if (!check[ny][nx])
					{
						check[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
		}

		printf("#%d %d\n", t, ans);
	}
	return 0;
}