#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> que1, que2;
    int x = 0, n = 0, step = 1;
    cin >> x >> n;
    int ans = x;
    while (step < n) {
        que1.push(2 * ans + 1);
        que2.push(3 * ans + 1);
        if (que1.front() > que2.front()) {
            ans = que2.front();
            que2.pop();
        } else if (que1.front() < que2.front()) {
            ans = que1.front();
            que1.pop();
        } else {
            ans = que1.front();
            que1.pop();
            que2.pop();
        }
        step++;
    }
    cout << ans << endl;
}