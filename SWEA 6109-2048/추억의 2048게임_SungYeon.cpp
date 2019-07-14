#include <iostream>
#include <string>
#include <array>
#include <deque>

using namespace std;
typedef array<deque<int>, 20> deque_mat;
typedef array<array<int, 20>, 20> mat;
void Print_field(mat field, int N);
void Change_field(deque_mat &field, mat &result, int N, string S);

int main(void)
{
	int T, N, tmp;
	string S;
	deque_mat field;
	mat result;

	freopen("s_input.txt", "r", stdin);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> S;
		for (int i = 0; i < N * N; i++)
		{
			cin >> tmp;
			if (tmp != 0)
			{
				if (S == "up" || S == "down")
					field[i % N].push_back(tmp);
				else if (S == "left" || S == "right")
					field[i / N].push_back(tmp);
			}
		}
		Change_field(field, result, N, S);
		cout << '#' << t + 1 << endl;
		Print_field(result, N);
	}
	return 0;
}

void Change_field(deque_mat &field, mat &result, int N, string S)
{
	int m, n;

	if (S == "up")
	{
		m = 0, n = 0;
		for (int i = 0; i < N * N; i++)
		{
			if (field[i % N].empty() == 0)
			{
				result[m][n] = field[i % N].front();
				field[i % N].pop_front();
				if (field[i % N].empty() == 0 && field[i % N].front() == result[m][n])
				{
					result[m][n] = field[i % N].front() * 2;
					field[i % N].pop_front();
				}
			}
			else
				result[m][n] = 0;
			n++;
			if (n == N)
			{
				n = 0;
				m++;
			}
		}
	}
	else if (S == "down")
	{
		m = N - 1, n = 0;
		for (int i = 0; i < N * N; i++)
		{
			if (field[i % N].empty() == 0)
			{
				result[m][n] = field[i % N].back();
				field[i % N].pop_back();
				if (field[i % N].empty() == 0 && field[i % N].back() == result[m][n])
				{
					result[m][n] = field[i % N].back() * 2;
					field[i % N].pop_back();
				}
			}
			else
				result[m][n] = 0;
			n++;
			if (n == N)
			{
				n = 0;
				m--;
			}
		}
	}
	else if (S == "left")
	{
		m = 0, n = 0;
		for (int i = 0; i < N * N; i++)
		{
			if (field[i % N].empty() == 0)
			{
				result[m][n] = field[i % N].front();
				field[i % N].pop_front();
				if (field[i % N].empty() == 0 && field[i % N].front() == result[m][n])
				{
					result[m][n] = field[i % N].front() * 2;
					field[i % N].pop_front();
				}
			}
			else
				result[m][n] = 0;
			m++;
			if (m == N)
			{
				m = 0;
				n++;
			}
		}
	}
	else if (S == "right")
	{
		m = 0, n =  N - 1;
		for (int i = 0; i < N * N; i++)
		{
			if (field[i % N].empty() == 0)
			{
				result[m][n] = field[i % N].back();
				field[i % N].pop_back();
				if (field[i % N].empty() == 0 && field[i % N].back() == result[m][n])
				{
					result[m][n] = field[i % N].back() * 2;
					field[i % N].pop_back();
				}
			}
			else
				result[m][n] = 0;
			m++;
			if (m == N)
			{
				m = 0;
				n--;
			}
		}
	}
}

void Print_field(mat field, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << field[i][j] << ' ';
		cout << endl;
	}
}