#include <iostream>

using namespace std;

int main(void)
{
	int T, open, cnt;
	char c, pre_c;

	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	scanf("%c", &c);
	for (int t = 0; t < T; t++)
	{
		open = 0;
		cnt = 0;
		pre_c = '\0';
		c = '\0';
		while (c != '\n' && c != EOF)
		{
			scanf("%c", &c);
			if (c == '(')
				open++;
			else if (c == ')')
			{
				if (pre_c == '(')
				{
					open--;
					cnt += open;
				}
				else
				{
					open--;
					cnt++;
				}
			}
			pre_c = c;
		}
		cout << '#' << t + 1 << ' ' << cnt << endl;
	}

	return 0;
}