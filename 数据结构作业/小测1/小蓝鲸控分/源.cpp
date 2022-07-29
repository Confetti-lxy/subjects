#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int cal(int n);

int main() {
    int n = 0;
    cin >> n;
    int ans = cal(n);
    cout << ans << endl;
}

int cal(int n) {
    int count = 0;
    for (int k = 1; k <= n; k++) {
        int sum = 0;
        for (int t = 0; t < n / k; t++) {
            sum += (k + t);
            if (sum >= n) {
                if (sum == n) {
                    count++;
                }
                break;
            }
        }
    }
    return count;
}