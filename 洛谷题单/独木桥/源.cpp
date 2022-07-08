#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int len = 0, n = 0;
    cin >> len >> n;
    int min_time = 0, max_time = 0, val = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        max_time = max(max_time, max(val, len - val + 1));
        min_time = max(min_time, min(val, len - val + 1));
    }
    cout << min_time << " " << max_time << endl;
}