#include <bits/stdc++.h>

using namespace std;

class Binary_Indexed_Tree {
private:
    vector<int> delta, values; // delta:差分数组, values:原数组
    int lowbit(int x);         //求二进制位
    void add(int loc, int val);

public:
    Binary_Indexed_Tree(vector<int> &nums);

    void update(int left, int right, int val);

    int ask(int loc);
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Binary_Indexed_Tree ans(nums);
    int mood = 0, x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++) {
        cin >> mood;
        if (mood == 1) {
            cin >> x >> y >> z;
            ans.update(x, y, z);
        } else {
            cin >> x;
            cout << ans.ask(x) << endl;
        }
    }
}

int Binary_Indexed_Tree::lowbit(int x) {
    return x & -x;
}

void Binary_Indexed_Tree::add(int loc, int val) {
    while (loc < delta.size()) {
        delta[loc] += val;
        loc += lowbit(loc);
    }
}

Binary_Indexed_Tree::Binary_Indexed_Tree(vector<int> &nums) {
    delta.resize(nums.size() + 1, 0);
    values = nums;
}

void Binary_Indexed_Tree::update(int left, int right, int val) {
    add(left, val);
    add(right + 1, -val);
}

int Binary_Indexed_Tree::ask(int loc) {
    int ans = values[loc - 1];
    while (loc >= 1) {
        ans += delta[loc];
        loc -= lowbit(loc);
    }
    return ans;
}