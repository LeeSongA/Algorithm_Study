#include <iostream>
#include <vector>
using namespace std;

int n, k;

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
		cin >> n >> k;
		vector <int> v[21];
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 1; j <= k; j++)
				{
					v[j].push_back(j + i * k);
				}
			}
			else
			{
				int cnt = 1;
				for (int j = k; j >= 1; j--)
					v[cnt++].push_back(j + i * k);
			}
		}
		int sum;
		printf("#%d ", t);
		for (int i = 1; i <= k; i++)
		{
			sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += v[i][j];
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
	return 0;
}