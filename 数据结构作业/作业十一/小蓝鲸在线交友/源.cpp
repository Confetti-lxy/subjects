#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class unionFinder {
private:
    vector<int> pre;
    vector<int> rank;

public:
    void initialize(int n);

    int find(int x);

    bool isSame(int x, int y);

    bool join(int x, int y);

    void cal(vector <vector<int>> &nums);

    int all_sets();
};

int main() {
    int n = 0;
    cin >> n;
    vector <vector<int>> nums(n, vector<int>(n, 0));
    unionFinder my_union;
    my_union.initialize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    my_union.cal(nums);
    int ans = my_union.all_sets();
    cout << ans << endl;
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

void unionFinder::cal(vector <vector<int>> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i][j] == 1) {
                if (!isSame(i, j)) {
                    join(i, j);
                }
            }
        }
    }
}

int unionFinder::all_sets() {
    unordered_set<int> sets;
    for (int i = 0; i < pre.size(); i++) {
        if (sets.find(find(i)) != sets.end()) {
            continue;
        }
        sets.insert(find(i));
    }
    return sets.size();
}