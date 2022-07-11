#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5 + 10;

struct node
{
    int left, right, index;

    node() : left(0), right(0), index(0) {}
};

node nums[mx];

void add(int loc, int val, int mood);

int main()
{
    int n = 0, m = 0;
    cin >> n;
    add(0, 1, 1);
    int x = 0, y = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> y;
        add(x, i, y);
    }
    cin >> m;
    while (m--)
    {
        cin >> x;
        nums[x].index = 1;
    }
    for (int i = nums[0].right; i; i = nums[i].right)
    {
        if (nums[i].index == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void add(int loc, int val, int mood)
{
    if (mood == 1)
    {
        nums[val].right = nums[loc].right;
        nums[val].left = loc;
        nums[loc].right = val;
        nums[nums[val].right].left = val;
    }
    else
    {
        nums[val].left = nums[loc].left;
        nums[val].right = loc;
        nums[loc].left = val;
        nums[nums[val].left].right = val;
    }
}
