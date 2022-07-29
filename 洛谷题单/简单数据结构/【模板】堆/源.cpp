#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> que;
    int n = 0, x = 0, y = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            que.push(y);
        } else if (x == 2) {
            cout << que.top() << endl;
        } else {
            que.pop();
        }
    }
    return 0;
}