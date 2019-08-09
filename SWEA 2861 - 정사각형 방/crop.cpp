#include <iostream>

#define SIZE 50

int farm[SIZE][SIZE];

int main(void)
{
	int T, n;

	scanf("%d", &T);
	int sum = 0;

	for (int t = 0; t < T; t++) {
		scanf("%d", &n);

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				scanf("%1d", &farm[y][x]);
		
		sum = farm[0][n / 2];

		for (int y = 1; y <= n/2; y++)
			for (int x = n / 2 - y; x <= n / 2 + y; x++)
				sum += farm[y][x];

		for (int y = n/2 + 1; y < n; y++)
			for (int x = n / 2 - (n - y - 1); x <= n / 2 + n - y - 1; x++)
				sum += farm[y][x];

		printf("#%d %d\n", t + 1, sum);
	}
} 