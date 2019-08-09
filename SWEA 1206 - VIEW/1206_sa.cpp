#include <iostream>

using namespace std;

int main() {
    int testCase, *arr;
    
    for (int i = 1; i <= 10; i++) {    
        cin >> testCase;
        arr = new int[testCase];
        int answer = 0;
        
        for (int j = 0; j < testCase; j++) {
            cin >> arr[j];
        }

        for (int k = 2; k < testCase - 2; k++) {
            int temp = arr[k];
            while (temp--) {
                if (temp >= arr[k - 1] && temp >= arr[k + 1] && temp >= arr[k - 2] && temp >= arr[k + 2]) {
                    answer++;
                }
                else {
                    break;
                }
            }
        }
        cout << "#" << i << " " << answer << endl;
    }
    
    return 0;
}
