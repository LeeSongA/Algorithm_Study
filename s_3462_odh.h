#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;

double a, b;
bool pcheck[101];
long long int dp[31][31];


int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	
	pcheck[0] = true;
	pcheck[1] = true;
	for (int i = 2; i*i <= 100; i++)
	{
		if (!pcheck[i])
		{
			for (int j = i * i; j <= 30; j += i)
			{
				if(!pcheck[j])
					pcheck[j] = true;
			}
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			if (j == 0 || i == 1 || i == j)
				dp[i][j] = 1;
			else if (j == 1 || j == i - 1)
				dp[i][j] = i;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> a >> b;

		vector<double> v1, v2;
		for (int i = 0; i <= 30; i++)
		{
			if (pcheck[i])
			{

				double temp1 = dp[30][i] * pow(a / 100, i) * pow((100 - a) / 100, 30 - i);
				double temp2 = dp[30][i] * pow(b / 100, i) * pow((100 - b) / 100, 30 - i);
				v1.push_back(temp1);
				v2.push_back(temp2);
			}
		}
		double ans = 0;
		for (int i = 0; i < v1.size(); i++)
		{
			for (int j = 0; j < v2.size(); j++)
			{
				ans += v1[i] * v2[j];
			}
		}

		printf("#%d %.5lf\n", t, 1 - ans);
	}
	return 0;
}