#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
    int start, end;
};

class Solution {
private:
    vector <vector<edge>> edges, back;
    vector<int> points, all_points;

public:
    void initialize(int n);

    int get_points();
};

int main() {
    int n = 0;
    cin >> n;
    Solution solution;
    solution.initialize(n);
    int ans = solution.get_points();
    cout << ans << endl;
}

void Solution::initialize(int n) {
    points.resize(n + 1);
    edges.resize(n + 1);
    back.resize(n + 1);
    all_points.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> points[i];
    }
    int x = 0, y = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        edges[x].push_back({x, y});
        back[y].push_back({y, x});
    }
}

int Solution::get_points() {
    queue<int> que;
    for (int i = 1; i <= edges.size(); i++) {
        if (edges[i].size() == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int n = que.size();
        for (int i = 0; i < n; i++) {
            auto it = que.front();
            que.pop();
            if (edges[it].size() == 0) {
                all_points[it] = points[it];
            } else {
                int sum = points[it];
                for (int j = 0; j < edges[it].size(); j++) {
                    int x = edges[it][j].end;
                    if (all_points[x] > 0) {
                        sum += all_points[x];
                    }
                }
                all_points[it] = sum;
            }
            for (int t = 0; t < back[it].size(); t++) {
                que.push(back[it][t].end);
            }
        }
    }
    return *max_element(all_points.begin() + 1, all_points.end());
}