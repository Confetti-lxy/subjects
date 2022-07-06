#include <bits/stdc++.h>

using namespace std;

class Binary_Indexed_Tree
{
private:
    vector<long long> bit, values; // bit:和数组, values:原数组
    int lowbit(int x);

public:
    Binary_Indexed_Tree(vector<long long> &nums);

    long long getSum(int loc);

    void add(int loc, int val);

    void update(int loc, int val);

    long long sumRange(int left, int right);
};

int main()
{
    long long n = 0, m = 0;
    cin >> n >> m;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Binary_Indexed_Tree ans(nums);
    int x = 0, y = 0, z = 0;
    vector<long long> res;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        if (x == 1)
        {
            //            ans.update(y, nums[y - 1] + z);
            ans.add(y, z);
        }
        else
        {
            res.push_back(ans.sumRange(y, z));
            //            cout << ans.sumRange(y, z) << endl;
        }
    }
    for (auto num : res)
    {
        cout << num << endl;
    }
}

int Binary_Indexed_Tree::lowbit(int x)
{
    return x & -x;
}

void Binary_Indexed_Tree::add(int loc, int val)
{
    while (loc <= bit.size())
    {
        bit[loc] += val;
        loc += lowbit(loc);
    }
}

Binary_Indexed_Tree::Binary_Indexed_Tree(vector<long long> &nums)
{
    bit.resize(nums.size() + 1, 0);
    values = nums;
    for (int i = 0; i < nums.size(); i++)
    {
        add(i + 1, nums[i]);
    }
}

long long Binary_Indexed_Tree::getSum(int loc)
{
    long long ans = 0;
    while (loc != 0)
    {
        ans += bit[loc];
        loc -= lowbit(loc);
    }
    return ans;
}

void Binary_Indexed_Tree::update(int loc, int val)
{
    add(loc, val - values[loc - 1]);
    values[loc - 1] = val;
}

long long Binary_Indexed_Tree::sumRange(int left, int right)
{
    return getSum(right) - getSum(left - 1);
}