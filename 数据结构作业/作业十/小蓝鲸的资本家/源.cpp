#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal(vector<int> nums, int val, int target);

int main()
{
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long left = 0, right = n - 1;
    while (left <= right)
    {
        int middle = (left + right) >> 1;
        int val = nums[middle];
        if (cal(nums, val, target) == 1)
        {
            left = middle + 1;
        }
        else if (cal(nums, val, target) == -1)
        {
            right = middle - 1;
        }
        else
        {
            cout << val << endl;
            return 0;
        }
    }
    int val = nums[left];
    while (cal(nums, val, target) == -1)
    {
        val--;
    }
    cout << val << endl;
}

int cal(vector<int> nums, int val, int target)
{
    long sum_value = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= val)
        {
            sum_value += (nums[i] - val);
        }
    }
    if (sum_value > target)
    {
        return 1;
    }
    else if (sum_value == target)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}