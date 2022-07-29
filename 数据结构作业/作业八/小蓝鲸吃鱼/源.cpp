#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int n = 20005;
    int father[20005];

    void init() {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u;
    }

    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

public:
    int removeStones(vector <vector<int>> &loc);
};

int main() {
    int n = 0;
    cin >> n;
    vector <vector<int>> locations(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        cin >> locations[i][0] >> locations[i][1];
    }
    Solution solution;
    cout << solution.removeStones(locations) << endl;
}

int Solution::removeStones(vector <vector<int>> &loc) {
    init();
    for (int i = 0; i < loc.size(); i++)
        join(loc[i][0], loc[i][1] + 10000);
    unordered_map<int, bool> my_map;
    for (int i = 0; i < loc.size(); i++) {
        my_map[find(loc[i][0])] = true;
        my_map[find(loc[i][1] + 10000)] = true;
    }
    return loc.size() - my_map.size();
}
