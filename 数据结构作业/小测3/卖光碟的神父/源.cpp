#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void longestValidParentheses(string s);

int main()
{
    string my_str;
    cin >> my_str;
    longestValidParentheses(my_str);
}

void longestValidParentheses(string s)
{
    int size = s.length();
    vector<int> dp(size, 0);
    int maxVal = 0;
    for (int i = 1; i < size; i++)
    {
        if (s[i] == 'S')
        {
            if (s[i - 1] == 'M')
            {
                dp[i] = 2;
                if (i - 2 >= 0)
                {
                    dp[i] = dp[i] + dp[i - 2];
                }
            }
            else if (dp[i - 1] > 0)
            {
                if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == 'M')
                {
                    dp[i] = dp[i - 1] + 2;
                    if ((i - dp[i - 1] - 2) >= 0)
                    {
                        dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
                    }
                }
            }
        }
        maxVal = max(maxVal, dp[i]);
    }
    cout << maxVal << endl;
    return;
}
