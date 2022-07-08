#include <bits/stdc++.h>

using namespace std;

int all[1000005] = {0}, nums[1000005][2] = {0}, ct[1000005] = {0}, ans = 0;

bool same(int a, int b);

void dfs(int i);

int main()
{
    int n = 0, val = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
    }
    all[0] = 1005;
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= 2; ++k)
        {
            cin >> val;
            nums[i][k] = (val != -1) ? val : 0;
        }
    dfs(1);
    cout << ans << endl;
}

bool same(int a, int b) //判断两节点是否对称
{
    if (a == b)
    {
        return 1;
    }
    if (!a || !b)
    {
        return 0;
    }
    return all[a] == all[b] && same(nums[a][1], nums[b][2]) && same(nums[a][2], nums[b][1]);
}

void dfs(int i) //大法师搜索
{
    if (i == 0)
    {
        return;
    }
    dfs(nums[i][1]);
    dfs(nums[i][2]);
    ct[i] = 1 + ct[nums[i][1]] + ct[nums[i][2]];
    all[i] += all[nums[i][1]] + all[nums[i][2]];
    if (ans < ct[i] && same(nums[i][1], nums[i][2]))
    {
        ans = ct[i];
    }
}