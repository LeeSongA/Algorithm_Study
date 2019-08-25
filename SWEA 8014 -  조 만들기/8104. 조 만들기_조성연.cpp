#include <iostream>
#include <algorithm>

#define SIZE 21

using namespace std;

int main(void)
{
	int T, N, K, index;
	bool up;
	int result[SIZE] = { 0 };

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;

		up = true;
		index = 0;
		fill(result, result + SIZE - 1, 0);
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <= K; j++)
			{
				result[index] += i * K + j;
				if (up)
					index++;
				else
					index--;
			}
			if (up)
			{
				up = false;
				index--;
			}
			else
			{
				up = true;
				index++;
			}
		}
		cout << '#' << t + 1 << ' ';
		for (int i = 0; i < K; i++)
			cout << result[i] << ' ';
		cout << endl;
	}

	return 0;
}