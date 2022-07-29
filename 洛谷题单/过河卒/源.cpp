#include <iostream>
#include <vector>

using namespace std;

void obstacle(vector <vector<int>> &nums, int x, int y);

long cal(vector <vector<int>> &nums, int x, int y);

int main() {
    int a = 0, b = 0, x = 0, y = 0;
    cin >> a >> b >> x >> y;
    vector <vector<int>> nums(a + 1, vector<int>(b + 1, 0));
    obstacle(nums, x, y);
    long ans = cal(nums, a, b);
    cout << ans << endl;
}

void obstacle(vector <vector<int>> &nums, int x, int y) {
    int n = nums.size(), m = nums[0].size();
    nums[x][y] = 1;
    if (x >= 2 && y >= 1) {
        nums[x - 2][y - 1] = 1;
    }
    if (x >= 1 && y >= 2) {
        nums[x - 1][y - 2] = 1;
    }
    if (x + 2 < n && y + 1 < m) {
        nums[x + 2][y + 1] = 1;
    }
    if (x + 1 < n && y + 2 < m) {
        nums[x + 1][y + 2] = 1;
    }
    if (x >= 2 && y + 1 < m) {
        nums[x - 2][y + 1] = 1;
    }
    if (x >= 1 && y + 2 < m) {
        nums[x - 1][y + 2] = 1;
    }
    if (y >= 2 && x + 1 < n) {
        nums[x + 1][y - 2] = 1;
    }
    if (y >= 1 && x + 2 < n) {
        nums[x + 2][y - 1] = 1;
    }
    return;
}

long cal(vector <vector<int>> &nums, int x, int y) {
    vector <vector<long>> dp(x + 1, vector<long>(y + 1, 0));
    for (int i = 0; i <= x; i++) {
        if (nums[i][0] != 1) {
            dp[i][0] = 1;
        } else {
            break;
        }
    }
    for (int i = 0; i <= y; i++) {
        if (nums[0][i] != 1) {
            dp[0][i] = 1;
        } else {
            break;
        }
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (nums[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[x][y];
}