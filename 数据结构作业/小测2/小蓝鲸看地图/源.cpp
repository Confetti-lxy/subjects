#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] == 1)
            {
                int count = 4;
                if (i >= 1 && nums[i - 1][j] == 1)
                {
                    count--;
                }
                if (j >= 1 && nums[i][j - 1] == 1)
                {
                    count--;
                }
                if (i < n - 1 && nums[i + 1][j] == 1)
                {
                    count--;
                }
                if (j < m - 1 && nums[i][j + 1] == 1)
                {
                    count--;
                }
                ans += count;
            }
        }
    }
    cout << ans << endl;
}