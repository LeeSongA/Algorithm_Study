#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 200000
using namespace std;

bool table[SIZE];

int main(void)
{
	int T, N, tmp, cnt;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		cnt = 0;
		fill(table, table + SIZE, 0);
		for (int n = 0; n < N; n++)
		{
			cin >> tmp;
			table[tmp] = true;
			if (table[tmp - 1] == false)
				cnt++;
		}
		cout << '#' << t + 1 << ' ' << cnt << '\n';
	}
	return 0;
}
