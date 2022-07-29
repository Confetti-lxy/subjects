#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct point {
    int start, end, length;

    point() : start(0), end(0), length(0) {}

    point(int x, int y, int z) : start(x), end(y), length(z) {}

    bool operator<(const point &p) const {
        return length > p.length;
    }
};

class unionFinder {
private:
    vector<int> pre;
    vector<int> rank;

public:
    void initialize(int n);

    int find(int x);

    bool isSame(int x, int y);

    bool join(int x, int y);
};

class Solution : unionFinder {
public:
    int cal(int n, int m);
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    Solution solution;
    int ans = solution.cal(n, m);
    if (ans == -1) {
        cout << "orz" << endl;
    } else {
        cout << ans << endl;
    }
}

void unionFinder::initialize(int n) {
    pre.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
        rank[i] = 1;
    }
}

int unionFinder::find(int x) {
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

bool unionFinder::isSame(int x, int y) {
    return find(x) == find(y);
}

bool unionFinder::join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (rank[x] > rank[y]) {
        pre[y] = x;
    } else if (rank[x] < rank[y]) {
        pre[x] = y;
    } else {
        pre[x] = y;
        rank[y]++;
    }
    return true;
}

int Solution::cal(int n, int m) {
    initialize(n + 1);
    int x = 0, y = 0, z = 0;
    priority_queue <point> que;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        que.push(point(x, y, z));
    }
    int count = 0, distances = 0;
    while (count < n - 1 && !que.empty()) {
        auto it = que.top();
        que.pop();
        if (!isSame(it.start, it.end)) {
            distances += it.length;
            count += 1;
            join(it.start, it.end);
        }
    }
    if (count == n - 1) {
        return distances;
    } else {
        return -1;
    }
}