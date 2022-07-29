#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    vector <vector<int>> edge;
    vector<int> value, d;
    vector <vector<pair < int, int>>>
    graph;

    void cal();

    void triangle();

public:
    void initialize(int n, int m);

    int maxValue();
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    Solution solution;
    solution.initialize(n, m);
    int ans = solution.maxValue();
    cout << ans << endl;
}

void Solution::initialize(int n, int m) {
    value.resize(n, 0);
    edge.resize(0);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    int x = 0, y = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        edge.push_back({x, y});
    }
}

void Solution::cal() {
    int n = value.size();
    d.resize(n, 0);
    sort(edge.begin(), edge.end(),
         [&](vector<int> &a, vector<int> &b) { return value[a[0]] + value[a[1]] > value[b[0]] + value[b[1]]; });
    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i][0], y = edge[i][1];
        d[x]++;
        d[y]++;
    }
    return;
}

void Solution::triangle() {
    int n = value.size(), m = edge.size();
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        if (d[edge[i][0]] < d[edge[i][1]]) {
            graph[edge[i][0]].push_back({edge[i][1], i});
        } else if (d[edge[i][0]] == d[edge[i][1]] && edge[i][0] < edge[i][1]) {
            graph[edge[i][0]].push_back({edge[i][1], i});
        } else {
            graph[edge[i][1]].push_back({edge[i][0], i});
        }
    }
}

int Solution::maxValue() {
    int n = value.size(), m = edge.size(), res = 0;
    vector<int> start(n, INT_MAX), end(n);
    vector <vector<int>> nodes(m), dis(n);
    cal();
    triangle();
    for (int i = 0; i < m; i++) {
        for (auto it: graph[edge[i][0]]) {
            start[it.first] = i, end[it.first] = it.second;
        }
        for (auto it: graph[edge[i][1]]) {
            if (start[it.first] == i) {
                nodes[it.second].push_back(edge[i][0]);
                nodes[end[it.first]].push_back(edge[i][1]);
                nodes[i].push_back(it.first);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < nodes[i].size(); j++) {
            dis[nodes[i][j]].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        int size = dis[i].size(), bound = size - 1;
        for (int j = 0; j < min(3, size) && bound >= j; j++) {
            for (int k = j; k <= bound; k++) {
                int cur = value[i] + value[edge[dis[i][j]][0]] + value[edge[dis[i][j]][1]], cnt = 0;
                if (edge[dis[i][k]][0] != edge[dis[i][j]][0] && edge[dis[i][k]][0] != edge[dis[i][j]][1]) {
                    cur += value[edge[dis[i][k]][0]];
                    cnt++;
                }
                if (edge[dis[i][k]][1] != edge[dis[i][j]][0] && edge[dis[i][k]][1] != edge[dis[i][j]][1]) {
                    cur += value[edge[dis[i][k]][1]];
                    cnt++;
                }
                res = max(res, cur);
                if (cnt == 2) {
                    bound = k - 1;
                    break;
                }
            }
        }
    }
    return res;
}