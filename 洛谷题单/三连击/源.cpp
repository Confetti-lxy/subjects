#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums(10, 0);
    int flag = 1;
    for (int i = 123; i < 333; i++)
    {
        nums.clear();
        nums.resize(10, 0);
        flag = 1;
        int x = i, y = i * 2, z = i * 3;
        while (x != 0)
        {
            nums[x % 10]++;
            x /= 10;
        }
        while (y != 0)
        {
            nums[y % 10]++;
            y /= 10;
        }
        while (z != 0)
        {
            nums[z % 10]++;
            z /= 10;
        }
        for (int j = 1; j < 10; j++)
        {
            if (nums[j] == 0)
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            cout << i << " " << i * 2 << " " << i * 3 << endl;
        }
    }
    return 0;
}