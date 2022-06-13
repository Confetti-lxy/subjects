#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
vector<vector<int>> nums;

void cal(int start, vector<int> &distances);

int main()
{
    int n, start, end;
    cin >> n >> start >> end;
    vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        nums[i].push_back(i);
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        nums[x - 1].push_back(y - 1);
        nums[y - 1].push_back(x - 1);
    }
    cal(start - 1, dist1);
    cal(end - 1, dist2);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist1[i] > dist2[i])
        {
            res = (res > dist1[i]) ? res : dist1[i];
        }
    }
    cout << res;
}

void cal(int start, vector<int> &dist)
{
    int n = nums.size();
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> my_pair;
    my_pair.push({0, start});
    while (!my_pair.empty())
    {
        pair<int, int> it = my_pair.top();
        int val = it.first, x = it.second;
        my_pair.pop();
        for (int j = 0; j < nums[x].size(); j++)
        {
            int next = nums[x][j];
            if (dist[next] > val + 1)
            {
                dist[next] = val + 1;
                my_pair.push({dist[next], next});
            }
        }
    }
}