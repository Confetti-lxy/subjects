#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct value
{
    int num1, num2;
    int score;
    bool operator<(const value &other) const
    {
        return score > other.score;
    }
};

int game(vector<value> &values);

int main()
{
    int n = 0;
    cin >> n;
    vector<value> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i].num1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i].num2;
    }
    for (int i = 0; i < n; i++)
    {
        values[i].score = values[i].num1 + values[i].num2;
    }
    int ans = game(values);
    cout << ans << endl;
}

int game(vector<value> &values)
{
    int n = values.size();
    sort(values.begin(), values.end());
    vector<int> book(n, 0);
    int value1 = 0, value2 = 0, flag = 0, loc = n - 1;
    if (values.size() == 2)
    {
        value1 = values[0].num1;
        value2 = values[1].num2;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (flag == 0)
            {
                int val = values[loc].score, max_num = values[loc].num1, t = loc;
                for (int j = loc; j >= 0 && values[j].score == val; j--)
                {
                    if (book[j] == 0 && values[j].num1 > max_num)
                    {
                        t = j;
                        max_num = values[j].num1;
                    }
                }
                value1 += values[t].num1;
                book[t] = 1;
                if (t == loc)
                {
                    while (book[loc] != 0)
                    {
                        loc--;
                    }
                }
                flag = 1;
            }
            else
            {
                int val = values[loc].score, max_num = values[loc].num2, t = loc;
                for (int j = loc; j >= 0 && values[j].score == val; j--)
                {
                    if (book[j] == 0 && values[j].num2 > max_num)
                    {
                        t = j;
                        max_num = values[j].num2;
                    }
                }
                value2 += values[t].num2;
                book[t] = 1;
                if (t == loc)
                {
                    while (book[loc] != 0)
                    {
                        loc--;
                    }
                }
                flag = 0;
            }
        }
    }
    if (value1 > value2)
    {
        return 1;
    }
    else if (value1 < value2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}