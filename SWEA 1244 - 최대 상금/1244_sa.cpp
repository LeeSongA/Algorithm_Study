#include <iostream>

using namespace std;

int n, ans;
string num;

void cal(int now, int cnt) {
    if(cnt == n) {
        ans = max(ans, stoi(num));
        return;
    }
    
    for(int i = now; i < num.size(); i++) {
        for(int j = i+1; j < num.size(); j++) {
            if(num[i] <= num[j]) {
                swap(num[i], num[j]);
                cal(i, cnt+1);
                swap(num[i], num[j]);
            }
        }
    }
}
        
int main() {
    int testCase;
    cin >> testCase;
    
    for (int t = 1; t <= testCase; t++) {
        cin >> num >> n;
        ans = 0;
        cal(0, 0);
        cout << "#" << t << " " << ans << endl;
    }
    
    return 0;
}
