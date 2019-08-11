#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

int T, ans;
int maxnum;
int n;
string in;
void go(int cur, int count)
{
	if (count == n)
	{
		maxnum = max(maxnum, stoi(in));
		return;
	}

	int len = in.length();
	for (int i = cur; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (in[i] <= in[j])
			{
				swap(in[i], in[j]);
				go(i, count + 1);
				swap(in[i], in[j]);
			}
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		maxnum = 0;
		cin >> in >> n;
		go(0, 0);
		printf("#%d %d\n", t, maxnum);
	}

	return 0;
}