#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct node
{
    int to, length, battle, index;
    node() : to(0), length(0), battle(0), index(0) {}
    node(int to, int length, int battle, int index) : to(to), length(length), battle(battle), index(index) {}
};

long ans = LONG_MAX, des = -1;
vector<int> costs, book;

void dfs(vector<vector<node>> &arr, int start, long distance, long battle, int index);

int main()
{
    int n = 0, m = 0, s = 0, e = 0;
    cin >> n >> m >> s >> e;
    vector<int> cities(m + 1, 0);
    vector<vector<node>> arr(n + 1);
    costs.resize(m + 1, 0), book.resize(n + 1, 0);
    des = e, book[s] = 1;
    for (int i = 1; i <= m; i++)
    {
        cin >> cities[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> costs[i];
    }
    for (int i = 1; i <= m; i++)
    {
        vector<int> city(cities[i], 0), time;
        for (int j = 0; j < cities[i]; j++)
        {
            cin >> city[j];
        }
        int val = 0;
        for (int j = 0; j < cities[i] - 1; j++)
        {
            cin >> val;
            time.push_back(val);
        }
        for (int j = 0; j < cities[i] - 1; j++)
        {
            cin >> val;
            int city1 = city[j], city2 = city[j + 1], t = time[j];
            arr[city1].push_back(node(city2, t, val, i));
        }
    }
    dfs(arr, s, 0, 0, 0);
    cout << ans << endl;
}

void dfs(vector<vector<node>> &arr, int start, long distance, long battle, int index)
{
    if (start == des)
    {
        ans = min(ans, ((distance + costs[index]) * battle));
        return;
    }
    int size = arr[start].size();
    for (int i = 0; i < size; i++)
    {
        int x = arr[start][i].to, y = arr[start][i].length, z = arr[start][i].battle, k = arr[start][i].index;
        if (book[x] == 0)
        {
            long dis = distance + y + ((index == k) ? 0 : costs[index]);
            long bat = battle + z;
            if (dis * bat < ans)
            {
                book[x] = 1;
                dfs(arr, x, dis, bat, k);
                book[x] = 0;
            }
        }
    }
    return;
}