#include <iostream>

#define SIZE 20

int board[SIZE][SIZE];
int tmp[SIZE];
int visit[SIZE];

int len;
char str[5];

enum { UP, DOWN, LEFT, RIGHT };

int main(void)
{
	int pos, N, T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d%s", &N, str);

		switch (str[0]) {
		case 'l':
			pos = LEFT;
			break;
		case 'r':
			pos = RIGHT;
			break;
		case 'u':
			pos = UP;
			break;
		case 'd':
			pos = DOWN;
			break;
		}
		
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				scanf("%d", &board[y][x]);

		if (pos == UP) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					if (board[y][x] != 0) {
						if (len == 0) {
							if (board[y][x] == tmp[len] && visit[len] == 0) {
								visit[len] = 1;
								tmp[len++] = 2 * board[y][x];
							}
							else if (tmp[len] != 0)
								tmp[++len] = board[y][x];
							else
								tmp[len++] = board[y][x];
						}
						else {
							if (board[y][x] == tmp[len - 1] && visit[len - 1] != 1) {
								visit[len - 1] = 1;
								tmp[len - 1] = 2 * board[y][x];
							}
							else
								tmp[len++] = board[y][x];
						}
							
					}
				}
				for (int y = 0; y < N; y++) {
					board[y][x] = tmp[y];
					tmp[y] = 0;
				}
				len = 0;
				for (int k = 0; k < N; k++)
					visit[k] = 0;
			}	
		}
		else if (pos == DOWN) {
			len = N - 1;
			for (int x = 0; x < N; x++) {
				for (int y = N - 1; y >= 0; y--) {
					if (board[y][x] != 0) {
						if (len == N - 1) {
							if (board[y][x] == tmp[len] && visit[len] == 0) {
								visit[len] = 1;
								tmp[len--] = 2 * board[y][x];
							}
							else if (tmp[len] != 0)
								tmp[--len] = board[y][x];
							else
								tmp[len--] = board[y][x];
						}
						else {
							if (board[y][x] == tmp[len + 1] && visit[len + 1] != 1) {
								visit[len + 1] = 1;
								tmp[len + 1] = 2 * board[y][x];
							}
							else
								tmp[len--] = board[y][x];
						}
					}
				}
				for (int y = N - 1; y >= 0; y--) {
					board[y][x] = tmp[y];
					tmp[y] = 0;
				}
				len = N - 1;
				for (int k = 0; k < N; k++)
					visit[k] = 0;
			}
		}
		else if (pos == LEFT) {
			len = 0;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (board[y][x] != 0) {
						if (len == 0) {
							if (board[y][x] == tmp[len] && visit[len] == 0) {
								visit[len] = 1;
								tmp[len++] = 2 * board[y][x];
							}
							else if (tmp[len] != 0)
								tmp[++len] = board[y][x];
							else
								tmp[len++] = board[y][x];
						}
						else {
							if (board[y][x] == tmp[len - 1] && visit[len - 1] != 1) {
								visit[len - 1] = 1;
								tmp[len - 1] = 2 * board[y][x];
							}
							else
								tmp[len++] = board[y][x];
						}

					}
				}
				for (int x = 0; x < N; x++) {
					board[y][x] = tmp[x];
					tmp[x] = 0;
				}
				len = 0;
				for (int k = 0; k < N; k++)
					visit[k] = 0;
			}
		}
		else if (pos == RIGHT) {
			for (int y = N - 1; y >= 0; y--) {
				for (int x = 0; x < N; x++) {
					if (board[y][x] != 0) {
						if (len == N - 1) {
							if (board[y][x] == tmp[len] && visit[len] == 0) {
								visit[len] = 1;
								tmp[len--] = 2 * board[y][x];
							}
							else if (tmp[len] != 0)
								tmp[--len] = board[y][x];
							else
								tmp[len--] = board[y][x];
						}
						else {
							if (board[y][x] == tmp[len + 1] && visit[len + 1] != 1) {
								visit[len + 1] = 1;
								tmp[len + 1] = 2 * board[y][x];
							}
							else
								tmp[len--] = board[y][x];
						}
					}
				}
				for (int x = N - 1; x >= 0; x--) {
					board[y][x] = tmp[x];
					tmp[x] = 0;
				}
				len = N - 1;
				for (int k = 0; k < N; k++)
					visit[k] = 0;
			}
		}
		printf("#%d\n", t + 1);

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++)
				printf("%d ", board[y][x]);
			printf("\n");
		}
	}
}