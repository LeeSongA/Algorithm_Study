#include <iostream>

using namespace std;

int main(void)
{
	int T, N, sum;
	int temp;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		sum = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			for (int i = 0; i < N; i++)
			{
				scanf("%1d", &temp);
				if (j <= N / 2)
				{
					if (i >= N / 2 - j && i <= N / 2 + j)
						sum += temp;
				}
				else
				{
					//if (i >= N / 2 - (N - j - 1) && i <= N / 2 + (N - j - 1))
					//	sum += temp;
					if (i >= j - N / 2 && i <= N / 2 + (N - j - 1))
						sum += temp;
				}

			}
		cout << '#' << t + 1 << ' ' << sum << endl;
	}
	return 0;
}