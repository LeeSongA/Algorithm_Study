#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int T, n;
int map[100][100];
int dist[100][100];
int ans;

void go()
{
	queue <pair<int, pair<int, int>>> q;
	q.push({ 0,{0,0} });

	while (!q.empty())
	{
		int sum = q.front().first;
		int cy = q.front().second.first;
		int cx = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (dist[ny][nx] > sum + map[ny][nx])
			{
				dist[ny][nx] = sum + map[ny][nx];
				q.push({ dist[ny][nx],{ny,nx} });
			}
		}
	}


}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(map, 0, sizeof(map));
		memset(dist, 0, sizeof(dist));

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%1d", &map[i][j]);
				dist[i][j] = 99999999;
			}
		}
		dist[0][0] = 0;
		go();

		printf("#%d %d\n", t, dist[n - 1][n - 1]);
	}
	return 0;
}