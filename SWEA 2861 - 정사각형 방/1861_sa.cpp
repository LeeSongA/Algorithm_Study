#include<iostream>
#include<algorithm>   
 
using namespace std;
 
int map[1000][1000];
int n;
int dist[1000][1000];

int move(int r, int c) {
    if (dist[r][c] > 0) {
        return dist[r][c];
    }
     // 위
    if (r - 1 >= 0 && map[r][c] == map[r - 1][c] - 1) {
        return dist[r][c] = move(r - 1, c) + 1;
    }
    // 아래
    if (r + 1 < n &&  map[r][c] == map[r + 1][c] - 1) {
        return dist[r][c] = move(r + 1, c) + 1;
    }
    // 오른쪽
    if (c + 1 < n &&  map[r][c] == map[r][c + 1] - 1) {
        return dist[r][c] = move(r, c + 1) + 1;
    }  
    // 왼쪽
    if (c - 1 >= 0 && map[r][c] == map[r][c - 1] - 1) {
        return dist[r][c] = move(r, c - 1) + 1;
    }
    return dist[r][c] = 1;
}
 
int main() {
    int testCase;
    cin >> testCase;
 
    for (int t = 1; t <= testCase; t++) {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            fill(dist[i], dist[i] + n, 0);
        }
        
        int max = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmpMax = move(i, j);
                
                if (tmpMax > max || (tmpMax == max && index > map[i][j])) {
                    index = map[i][j];
                    max = tmpMax;
                }
            }
        }
        
        cout << "#" << t << " " << index << " " << max << endl;
    }
    return 0;
}