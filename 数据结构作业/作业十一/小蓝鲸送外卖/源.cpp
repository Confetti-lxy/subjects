#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

struct edge
{
    int to, length;
    edge(int to, int length) : to(to), length(length) {}
};

struct point
{
    int number, distance;
    point(int number, int distance) : number(number), distance(distance) {}
    bool operator<(const point &p) const
    {
        return distance > p.distance;
    }
};

class Solution
{
private:
    vector<vector<edge>> edges;
    vector<int> dis, vis;

public:
    long initialize(int n, int m);
    vector<int> dijkstra(int x);
};

int main()
{
    int n = 0;
    cin >> n;
    Solution solution;
    long ans = solution.initialize(n, n - 1);
    vector<int> dis = solution.dijkstra(1);
    int max_distance = *max_element(dis.begin() + 1, dis.end());
    cout << ans - max_distance << endl;
}

long Solution::initialize(int n, int m)
{
    edges.resize(n + 1);
    long sum = 0;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edges[x].push_back(edge(y, z));
        edges[y].push_back(edge(x, z));
        sum += 2 * z;
    }
    return sum;
}
vector<int> Solution::dijkstra(int x)
{
    dis.resize(edges.size(), INT_MAX);
    dis[x] = 0;
    vis.resize(edges.size(), 0);
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
                if (dis[end] > dis[val] + edges[val][i].length)
                {
                    dis[end] = edges[val][i].length + dis[val];
                    que.push(point(end, dis[end]));
                }
            }
        }
    }
    return dis;
}