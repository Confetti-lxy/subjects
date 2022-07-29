#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n = 0, m = 0, s = 0, e = 0, x = 0;
    // 输入---------------------------------------------------------------------------
    cin >> n >> m >> s >> e;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        int *nations = new int[x];
        for (int j = 0; j < x; j++) {
            cin >> nations[j];
        }
        int dis = 0;
        for (int j = 0; j < x - 1; j++) {
            cin >> dis;
            int nation1 = nations[j], nation2 = nations[j + 1];
            arr[nation1][nation2] = dis;
            arr[nation2][nation1] = dis;
        }
    }
    // 计算---------------------------------------------------------------------------
    int *ans = new int[n];
    int *book = new int[n];
    for (int i = 0; i < n; i++) {
        ans[i] = arr[s][i];
        if (i != s) {
            book[i] = 0;
        } else {
            book[i] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int min_dis = INT_MAX, loc = s;
        for (int j = 0; j < n; j++) {
            if (book[j] == 0 && ans[j] < min_dis) {
                min_dis = ans[j];
                loc = j;
            }
        }
        book[loc] = 1;
        for (int k = 0; k < n; k++) {
            int dist = arr[loc][k];
            if (book[k] == 0 && dist < INT_MAX && ans[loc] + dist < ans[k]) {
                ans[k] = dist + ans[loc];
            }
        }
    }
    // 输出结果-------------------------------------------------------------------------
    if (ans[e] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans[e] << endl;
    }
}