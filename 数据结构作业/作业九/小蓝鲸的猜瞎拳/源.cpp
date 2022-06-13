#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> pre, level;
    void initialize(int n);
    int find(int x);
    void Union(int x, int y);

public:
    int cal(int n, int m);
};

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    Solution solution;
    int res = solution.cal(n, m);
    cout << res << endl;
}

void Solution::initialize(int n)
{
    pre.resize(n + 1, 0);
    level.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
    }
    return;
}

int Solution::find(int x)
{
    if (x == pre[x])
    {
        return x;
    }
    int t = pre[x];
    pre[x] = find(pre[x]);
    level[x] = (level[x] + level[t]) % 3;
    return pre[x];
}

void Solution::Union(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    pre[fy] = fx;
    level[fy] = (level[x] - level[y] + 4) % 3;
    return;
}

int Solution::cal(int n, int m)
{
    initialize(n);
    int ans = 0, x = 0, y = 0;
    while (m--)
    {
        cin >> x >> y;
        if (x > n || y > n || x == y)
        {
            ans++;
        }
        else if (find(x) == find(y))
        {
            if ((level[x] + 1) % 3 != level[y])
            {
                ans++;
            }
        }
        else
        {
            Union(x, y);
        }
    }
    return ans;
}