#include <iostream>

#define SIZE 1000

int room[SIZE][SIZE];
int memoi[SIZE][SIZE];

int mv_x[] = { 0, 1, 0, -1 };
int mv_y[] = { 1, 0, -1, 0 };

int max_cnt;

void DFS(int pos_x, int pos_y, int N)
{
	int next_x, next_y;

	memoi[pos_y][pos_x] = 1;

	for (int i = 0; i < 4; i++) {
		next_x = pos_x + mv_x[i];
		next_y = pos_y + mv_y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
			continue;
		if (room[next_y][next_x] - room[pos_y][pos_x] != 1)
			continue;
		if(memoi[next_y][next_x] == 0)
			DFS(next_x, next_y, N);

		memoi[pos_y][pos_x] = memoi[pos_y][pos_x] > (memoi[next_y][next_x] + 1) ? memoi[pos_y][pos_x] : memoi[next_y][next_x] + 1;
	}
}

int main(void)
{
	int T, N, max_cnt, max_room;
	
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		max_cnt = 0;

		scanf("%d", &N);

		for(int y = 0; y < N; y++)
			for (int x = 0; x < N; x++) {
				scanf("%d", &room[y][x]);
				memoi[y][x] = 0;
			}

		for(int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				DFS(x, y, N);

		for(int y = 0; y < N; y++)
		for (int y = 0; y < N; y++)
			for(int x = 0; x < N; x++)
				if (memoi[y][x] > max_cnt) {
					max_cnt = memoi[y][x];
					max_room = room[y][x];
				}
		printf("#%d %d %d\n", t + 1, max_room, max_cnt);
	}
}