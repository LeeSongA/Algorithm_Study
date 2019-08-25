#include <iostream>
#include <queue>

using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
typedef pair<int, int> pt;
int r, c;
char map[26][26];
bool check[26][26];
int my, mx, zy, zx;
int ey, ex;
queue <pair<int, int>> mq;

void checkdir()
{
	bool cd[4] = { 0, };
	for (int i = 0; i < 4; i++)
	{
		int ny = ey + dy[i];
		int nx = ex + dx[i];

		if (ny<1 || nx<1 || ny>r || nx>c)
			continue;
		if (map[ny][nx] == '1')
		{
			if (i == 1 || i == 3)
				cd[i] = true;
		}

		if (map[ny][nx] == '2')
		{
			if (i == 2 || i == 1)
				cd[i] = true;
		}

		if (map[ny][nx] == '3')
		{
			if (i == 2 || i == 0)
				cd[i] = true;
		}

		if (map[ny][nx] == '4')
		{
			if (i == 0 || i == 3)
				cd[i] = true;
		}

		if (map[ny][nx] == '5')
		{
			if (i == 2 || i == 3)
				cd[i] = true;
		}

		if (map[ny][nx] == '6')
		{
			if (i == 1 || i == 0)
				cd[i] = true;
		}

		if (map[ny][nx] == '7')
			cd[i] = true;
		
	}
	if (cd[0] && cd[1] && cd[2] && cd[3])
	{
		printf("%c", '+');
		return;
	}
	if (cd[0] && cd[2])
		printf("%d", 1);
	if (cd[3] && cd[0])
		printf("%d", 2);
	if (cd[3] && cd[1])
		printf("%d", 3);
	if (cd[1] && cd[2])
		printf("%d", 4);
	if (cd[3] && cd[2])
		printf("%c", '|');
	if (cd[1] && cd[0])
		printf("%c", '-');
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '|')
				map[i][j] = '5';
			if (map[i][j] == '-')
				map[i][j] = '6';
			if (map[i][j] == '+')
				map[i][j] = '7';
			if (map[i][j] == 'M')
			{
				my= i;
				mx = j;
			}
			if (map[i][j] == 'Z')
			{
				zy = i;
				zx = j;
			}
		}
	}
	
	
	check[my][mx] = true;
	mq.push({ my,mx });
	while (!mq.empty())
	{
		int cy = mq.front().first;
		int cx = mq.front().second;
		mq.pop();

		if (map[cy][cx] == '.')
		{
			check[cy][cx] = false;
			ey = cy;
			ex = cx;
			break;
		}
		if (map[cy][cx] == 'M')
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 1 || nx < 1 || ny > r || nx > c)
					continue;

				if (map[ny][nx] >= '1' && map[ny][nx] <= '7')
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}
			}
		}
		else
		{
			int ny, nx, nd;
			if (map[cy][cx] == '1')
			{
				nd = 0;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}

				nd = 2;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}
			}

			if (map[cy][cx] == '2')
			{
				nd = 3;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}

				nd = 0;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}
			}

			if (map[cy][cx] == '3')
			{
				nd = 3;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}

				nd = 1;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}
			}

			if (map[cy][cx] == '4')
			{
				nd = 1;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}

				nd = 2;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}
			}

			if (map[cy][cx] == '5')
			{
				nd = 3;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}

				nd = 2;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}
			}

			if (map[cy][cx] == '6')
			{
				nd = 0;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}

				nd = 1;
				ny = cy + dy[nd];
				nx = cx + dx[nd];

				if (!check[ny][nx])
				{
					check[ny][nx] = true;
					mq.push({ ny,nx });
				}
			}

			if (map[cy][cx] == '7')
			{
				for (int i = 0; i < 4; i++)
				{
					ny = cy + dy[i];
					nx = cx + dx[i];

					if (!check[ny][nx])
					{
						check[ny][nx] = true;
						mq.push({ ny,nx });
					}
				}
			}
		}
	}
	

	printf("%d %d ", ey, ex);
	checkdir();
	return 0;
}