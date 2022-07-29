#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector <vector<int>> &distances, vector<int> &book, int loc);

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector <vector<int>> distance(n + 1);
    vector<int> book(n + 1, 0);
    int x = 0, y = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        distance[x].push_back(y);
        distance[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (book[i] == 0) {
            count++;
            book[i] = 1;
            dfs(distance, book, i);
        }
    }
    cout << count - 1 << endl;
}

void dfs(vector <vector<int>> &distances, vector<int> &book, int loc) {
    queue<int> my_que;
    my_que.push(loc);
    while (!my_que.empty()) {
        auto it = my_que.front();
        my_que.pop();
        for (int i = 0; i < distances[it].size(); i++) {
            int val = distances[it][i];
            if (book[val] == 0) {
                book[val] = 1;
                my_que.push(val);
            }
        }
    }
    return;
}