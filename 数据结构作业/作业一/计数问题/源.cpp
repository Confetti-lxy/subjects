#include <iostream>
using namespace std;

int main()
{
    int x, y, count = 0;
    cin >> x >> y;
    for (int i = 1; i <= x; i++)
    {
        int x = i;
        while (x > 0)
        {
            int m = x % 10;
            if (m == y)
            {
                count++;
            }
            x /= 10;
        }
    }
    cout << count << endl;
}