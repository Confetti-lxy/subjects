#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long ans = LONG_LONG_MAX;
int des = -1;
vector<int> cost, book;

struct node {
    int to, length, index;

    node() : to(0), length(0), index(0) {}

    node(int to, int length, int index) : to(to), length(length), index(index) {}
};

void dfs(vector <vector<node>> &arr, int start, long long distance, int index);

int main() {
    int n = 0, m = 0, s = 0, e = 0;
    cin >> n >> m >> s >> e;
    book.resize(n + 1, 0);
    des = e, book[s] = 1;
    vector <vector<node>> arr(n + 1);
    vector<int> cities(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> cities[i];
    }
    cost.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i <= m; i++) {
        vector<int> city(cities[i], 0);
        for (int j = 0; j < cities[i]; j++) {
            cin >> city[j];
        }
        int val = 0;
        for (int j = 0; j < cities[i] - 1; j++) {
            cin >> val;
            int city1 = city[j], city2 = city[j + 1];
            arr[city1].push_back(node(city2, val, i));
        }
    }
    dfs(arr, s, 0, 0);
    cout << ans << endl;
}

void dfs(vector <vector<node>> &arr, int start, long long distance, int index) {
    if (start == des) {
        ans = min(ans, distance + cost[index]);
        return;
    }
    int size = arr[start].size();
    for (int i = 0; i < size; i++) {
        int x = arr[start][i].to, y = arr[start][i].length, z = arr[start][i].index;
        if (book[x] == 0) {

            long long dis = distance + y + ((index == z) ? 0 : cost[index]);
            if (dis < ans) {
                book[x] = 1;
                dfs(arr, x, dis, z);
                book[x] = 0;
            }
        }
    }
    return;
}