#include <iostream>
#include <string.h>
using namespace std;

int n,ans;
int s[200001];

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
		memset(s, 0, sizeof(s));
		cin >> n;
		ans = 1;
		int temp;
		for (int i = 1; i <= n; i++)
		{
			cin >> temp;
			s[temp] = i;
			if (s[temp + 1] && s[temp] > s[temp + 1])
				ans++;
		}
		printf("#%d %d\n",t, ans);
	}
	return 0;
}