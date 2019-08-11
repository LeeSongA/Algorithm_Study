#include <iostream>
#include <vector>

using namespace std;

int max_result;
void Find_Max(int time, int size, int cnt, int orig[6]);
int results[1000];
vector<int> already_num;
vector<int> already_cnt;

int main(void)
{
	int T, num, tmp, time, size;
	int card[6];

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		size = 0;
		max_result = 0;
		while (already_num.empty() == 0)
		{
			already_num.pop_back();
			already_cnt.pop_back();
		}
		cin >> num >> time;
		tmp = num;
		while (tmp > 0)
		{
			tmp /= 10;
			size++;
		}
		for (int i = size - 1; i >= 0; i--)
		{
			card[i] = num % 10;
			num /= 10;
		}
		Find_Max(time, size, 0, card);
		cout << '#' << t + 1 << ' ' << max_result << endl;
	}
	return 0;
}

void Find_Max(int time, int size, int cnt, int orig[6])
{
	int temp_card[6], tmp;
	int result = 0;
	int i;

	for (i = 0; i < size - 1; i++)
	{
		result += orig[i];
		result *= 10;
	}
	result += orig[i];
	for (int j = 0; j < already_num.size(); j++)
	{
		if (result == already_num[j] && cnt == already_cnt[j])
			return;
	}
	already_num.push_back(result);
	already_cnt.push_back(cnt);

	if (time > cnt)
	{
		for (int i = 0; i < size; i++)
			temp_card[i] = orig[i];
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				tmp = temp_card[i];
				temp_card[i] = temp_card[j];
				temp_card[j] = tmp;
				Find_Max(time, size, cnt + 1, temp_card);
				tmp = temp_card[i];
				temp_card[i] = temp_card[j];
				temp_card[j] = tmp;
			}
		}
	}
	else
	{
		if (result > max_result)
			max_result = result;
	}
}