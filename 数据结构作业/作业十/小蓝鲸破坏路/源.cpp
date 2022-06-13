#include <iostream>
#include <vector>
using namespace std;

class unionFinder
{
private:
    vector<int> pre;
    vector<int> rank;

public:
    void initialize(int n);
    int find(int x);
    bool isSame(int x, int y);
    bool join(int x, int y);
};

class Solution : unionFinder
{
public:
    void cal(int n);
};

int main()
{
    int n = 0;
    Solution solution;
    cin >> n;
    solution.cal(n);
    return 0;
}

void unionFinder::initialize(int n)
{
    pre.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++)
    {
        pre[i] = i;
        rank[i] = 1;
    }
}

int unionFinder::find(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

bool unionFinder::isSame(int x, int y)
{
    return find(x) == find(y);
}

bool unionFinder::join(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (rank[x] > rank[y])
    {
        pre[y] = x;
    }
    else if (rank[x] < rank[y])
    {
        pre[x] = y;
    }
    else
    {
        pre[x] = y;
        rank[y]++;
    }
    return true;
}

void Solution::cal(int n)
{
    initialize(100005);
    vector<int> ans;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (!isSame(x, y))
        {
            join(x, y);
        }
        else
        {
            ans.push_back(x);
            ans.push_back(y);
        }
    }
    cout << ans[0] << " " << ans[1] << endl;
    return;
}