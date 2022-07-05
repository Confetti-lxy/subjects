#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

struct edge
{
    int to, length;

    edge() : to(0), length(0) {}

    edge(int x, int y) : to(x), length(y) {}
};

struct point
{
    int number, length;

    point() : number(0), length(0) {}

    point(int x, int y) : number(x), length(y) {}

    bool operator<(const point &p) const
    {
        return length > p.length;
    }
};

class Solution
{
private:
    vector<vector<edge>> edges;
    vector<int> dis, vis;

public:
    void initialize(int n, int m);

    vector<int> dijkstra(int x);
};

int main()
{
    int n = 0, m = 0, x = 0;
    cin >> n >> m >> x;
    Solution solution;
    solution.initialize(n, m);
    vector<int> ans = solution.dijkstra(x);
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void Solution::initialize(int n, int m)
{
    edges.resize(n + 1);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edges[x].push_back(edge(y, z));
    }
}

vector<int> Solution::dijkstra(int x)
{
    dis.resize(edges.size(), INT_MAX);
    vis.resize(edges.size(), 0);
    dis[x] = 0;
    priority_queue<point> que;
    que.push(point(x, 0));
    while (!que.empty())
    {
        auto it = que.top();
        que.pop();
        int val = it.number;
        if (vis[val] == 1)
        {
            continue;
        }
        vis[val] = 1;
        for (int i = 0; i < edges[val].size(); i++)
        {
            int end = edges[val][i].to;
            if (vis[end] == 0)
            {
                if (dis[end] > edges[val][i].length + dis[val])
                {
                    dis[end] = edges[val][i].length + dis[val];
                    que.push(point(end, dis[end]));
                }
            }
        }
    }
    return dis;
}