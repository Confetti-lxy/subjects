#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct node
{
    int to, length, index;
    node() : to(0), length(0), index(0) {}
    node(int to, int length, int index) : to(to), length(length), index(index) {}
};

struct point
{
    long dis, index;
    point() : dis(0), index(0) {}
    point(int dis, int index) : dis(dis), index(index) {}
};

vector<point> dijkstra(vector<vector<node>> &arr, vector<int> &costs, int start);

int main()
{
    int n = 0, m = 0, s = 0, e = 0;
    cin >> n >> m >> s >> e;
    vector<int> cities(m + 1, 0), costs(m + 1, 0);
    vector<vector<node>> arr(n + 1);
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
        vector<int> city(cities[i]);
        for (int j = 0; j < cities[i]; j++)
        {
            cin >> city[j];
        }
        int val = 0;
        for (int j = 0; j < cities[i] - 1; j++)
        {
            cin >> val;
            int city1 = city[j], city2 = city[j + 1];
            arr[city1].push_back(node(city2, val, i));
        }
    }
    vector<point> ans = dijkstra(arr, costs, s);
    cout << ans[e].dis << endl;
}

vector<point> dijkstra(vector<vector<node>> &arr, vector<int> &costs, int start)
{
    int n = arr.size();
    vector<point> ans(n, point(INT_MAX, 0));
    vector<int> book(n, 0);
    ans[start] = point(0, 0);
    for (int i = 0; i < arr[start].size(); i++)
    {
        int x = arr[start][i].to, y = arr[start][i].length, z = arr[start][i].index;
        ans[x] = point(y + costs[z], z);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int dis = INT_MAX, loc = -1;
        for (int j = 1; j < n; j++)
        {
            if (book[j] == 0 && dis > ans[j].dis)
            {
                dis = ans[j].dis;
                loc = j;
            }
        }
        book[loc] = 1;
        int index = ans[loc].index;
        for (int j = 0; j < arr[loc].size(); j++)
        {
            int x = arr[loc][j].to, y = arr[loc][j].length, z = arr[loc][j].index;
            if (book[x] == 0)
            {
                long dist = ans[loc].dis + y + ((index == z) ? 0 : costs[z]);
                if (ans[x].dis > dist)
                {
                    ans[x] = point(dist, index);
                }
            }
        }
    }
    return ans;
}