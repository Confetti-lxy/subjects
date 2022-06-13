#include <iostream>
#include <vector>
using namespace std;

vector<int> value;

void cal(int n, int loc);

int main()
{
    int m = 0, n = 0, start = 0, flag = 0;
    cin >> m >> n;
    vector<int> nums(n + 1);
    value.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        if (nums[i] == m)
        {
            start = i;
        }
    }
    cal(n, 1);
    int x = start / 2, y = start * 2, z = start * 2 + 1;
    if (x > 0 && flag == 0)
    {
        if (value[1] - value[start] > value[start])
        {
            flag = 1;
        }
    }
    if (y <= n && flag == 0)
    {
        if (value[y] > value[1] - value[y])
        {
            flag = 1;
        }
    }
    if (z <= n && flag == 0)
    {
        if (value[z] > value[1] - value[z])
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

void cal(int n, int loc)
{
    value[loc] = 1;
    if (loc * 2 <= n)
    {
        cal(n, loc * 2);
        value[loc] += value[loc * 2];
    }
    if (loc * 2 + 1 <= n)
    {
        cal(n, loc * 2 + 1);
        value[loc] += value[loc * 2 + 1];
    }
}