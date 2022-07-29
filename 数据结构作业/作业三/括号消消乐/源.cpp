#include <iostream>
#include <string>

using namespace std;

int f(string str);

int getscore(int help[], int x, int y);

int main() {
    string str;
    int k;
    cin >> k >> str;
    cout << f(str) << endl;
}

int f(string str) {
    int n = str.size();
    if (n < 2)
        return 0;
    int *dp = new int[n];
    int *help = new int[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 0;
        help[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        if (str[i] == ')') {
            if (str[i - 1] == '(') {
                dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;
                help[i] = i - 1;
                help[i - 1] = i;
            } else {
                if (i - dp[i - 1] > 0 && str[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0);
                    help[i] = i - dp[i - 1] - 1;
                    help[i - dp[i - 1] - 1] = i;
                }
            }
        }
    }
    int score = getscore(help, 0, n - 1);
    return score;
}

int getscore(int help[], int x, int y) {
    if (x >= y)
        return 0;
    int score = 0;
    for (int i = y; i >= x; i--) {
        if (help[i] != -1) {
            if (help[i] == i - 1) {
                score += 1;
                i--;
            } else {
                int m = help[i];
                score += 2 * getscore(help, m + 1, i - 1);
                i = help[i];
            }
        }
    }
    return score;
}