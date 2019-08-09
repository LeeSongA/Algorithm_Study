#include <iostream>

using namespace std;

int main() {
    int testCase;  
    cin >> testCase;

    for (int t = 1; t <= testCase; t++) {
        int N;
        cin >> N;
        char farm[49];
        int ans = 0;
        
        for(int r = 0; r < N/2; r++) {
            cin >> farm;
            
            for(int c = N / 2 - r; c <= N / 2 + r; c++) {
                ans += farm[c] - '0';
            }
        }
        
        for(int r = N/2; r < N; r++) {
            cin >> farm;
            
            for (int c = r - N/2; c < N - r + N/2; c++) 
                ans += farm[c] - '0';
        }
        
        cout << "#" << t << " " << ans << endl;
    }

	return 0;
}
