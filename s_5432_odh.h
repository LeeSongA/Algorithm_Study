#include <iostream>
#include <string.h>
#include <string>

using namespace std;

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
		bool check = false;
		int cnt = 0;
		string s;

		cin >> s;
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				check = true;
				cnt++;
			}
			else if (s[i] == ')' && check)
			{
				cnt--;
				ans += cnt;
				check = false;
			}
			else
			{
				cnt--;
				ans++;
				check = false;
			}
		}

		printf("#%d %d\n", t, ans);
	}
	
	return 0;
}