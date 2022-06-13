#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct state
{
    int x = 0;
    int y = 0;
    int step = 0;
};
vector<int> move_x = {0, 0, 1, -1};
vector<int> move_y = {1, -1, 0, 0};
vector<vector<int>> tp_location;

bool bfs(vector<vector<char>> &maze, vector<vector<bool>> &book, state a);
bool in(int x, int y, int n, int m);

int main()
{
    int x, y;
    state start;
    cin >> x >> y;
    vector<vector<char>> maze(x, vector<char>(y));
    vector<vector<bool>> book(x, vector<bool>(y, true));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
            {
                start.x = i;
                start.y = j;
            }
            else if (maze[i][j] == '*')
            {
                tp_location.push_back({i, j});
            }
        }
    book[start.x][start.y] = false;
    bool ans = bfs(maze, book, start);
    if (ans)
        cout << -1 << endl;
}

bool in(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool bfs(vector<vector<char>> &maze, vector<vector<bool>> &book, state a)
{
    int m = maze.size(), n = maze[0].size();
    queue<state> que;
    que.push(a);
    while (!que.empty())
    {
        state d = que.front();
        que.pop();
        state new_state;
        new_state.step = d.step + 1;
        if (maze[d.x][d.y] == 'E')
        {
            cout << d.step << endl;
            return false;
        }
        if (maze[d.x][d.y] == '*')
        {
            for (int j = 0; j < tp_location.size(); j++)
            {
                if (book[tp_location[j][0]][tp_location[j][1]])
                {
                    new_state.x = tp_location[j][0];
                    new_state.y = tp_location[j][1];
                    que.push(new_state);
                    book[new_state.x][new_state.y] = false;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int x = d.x + move_x[i];
            int y = d.y + move_y[i];
            if (in(x, y, m, n) && maze[x][y] != '1' && book[x][y])
            {
                new_state.x = x;
                new_state.y = y;
                que.push(new_state);
                book[x][y] = false;
            }
        }
    }
    return true;
}