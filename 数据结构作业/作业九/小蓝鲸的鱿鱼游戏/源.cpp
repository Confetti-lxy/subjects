#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void cal(vector<vector<pair<int, int>>> &edges, vector<int> &ans, int index);

int main()
{
    int n, a, b, flag = 1;
    cin >> n >> a >> b;
    unordered_map<int, int> my_map;
    vector<vector<pair<int, int>>> connect(n);
    vector<int> res(n, -1), book(n, 0), nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        my_map[nums[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int val = nums[i];
        if (my_map.count(a - val))
        {
            connect[i].push_back({my_map[a - val], 0});
            book[i]++;
        }
        if (my_map.count(b - val))
        {
            connect[i].push_back({my_map[b - val], 1});
            book[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (book[i] == 1)
        {
            cal(connect, res, i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (res[i] == -1)
        {
            if (nums[i] == a / 2)
            {
                res[i] = 0;
            }
            else if (nums[i] == b / 2)
            {
                res[i] = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << res[i] << " ";
        }
        cout << res[n - 1] << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

void cal(vector<vector<pair<int, int>>> &connect, vector<int> &ans, int index)
{
    for (int i = 0; i < connect[index].size(); i++)
    {
        int next = connect[index][i].first;
        int loc = connect[index][i].second;
        if (ans[next] == -1)
        {
            ans[index] = loc;
            ans[next] = loc;
            for (int j = 0; j < connect[next].size(); j++)
            {
                int value = connect[next][j].first;
                if (value != index && ans[value] == -1)
                {
                    cal(connect, ans, value);
                }
            }
        }
    }
}