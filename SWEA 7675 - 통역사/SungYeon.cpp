#include <iostream>
#include <string>
#include <array>
#include <cctype>

using namespace std;

void Print_Count_Name(char str[5][1001], int N);

int main(void)
{
	int T, N, i, n;
	char str[5][1001];
	char c = 'a';

	//freopen("s_input.txt", "r", stdin);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		i = 0;
		n = 0;
		cin >> N;
		while (n < N)
		{
			scanf("%c", &c);
			if (c != '\n')
				str[n][i++] = c;
			if (c == '.' || c == '?' || c == '!')
			{
				str[n][i] = '\0';
				i = 0;
				n++;
			}
		}
		cout << '#' << t + 1 << ' ';
		Print_Count_Name(str, N);
		cout << endl;
	}
	return 0;
}

void Print_Count_Name(char str[5][1001], int N)
{
	int i = 0, cnt = 0;
	bool flag = false;

	for (int n = 0; n < N; n++)
	{
		i = 0;
		cnt = 0;
		flag = false;
		while (str[n][i] != '\0')
		{
			if (str[n][i] == ' ' && flag == true)
				cnt++;
			if ((i == 0 || str[n][i - 1] == ' ') && isupper(str[n][i]))
				flag = true;
			else if (!islower(str[n][i]) && !((str[n][i + 1] == '\0' || str[n][i + 1] == ' ') && (str[n][i] == '.' || str[n][i] == '!' || str[n][i] == '?')))
				flag = false;
			i++;
		}
		if (flag == true)
			cnt++;
		cout << cnt << ' ';
	}
}