#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

bool judge(vector<int> &nums);

int find_max(vector<int> &nums, int start, int end);

int find_min(vector<int> &nums, int start, int end);

int main() {
    int n = 0;
    cin >> n;
    if (n <= 2) {
        return false;
    } else {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        bool ans = judge(nums);
        if (ans == false) {
            cout << "False" << endl;
        } else {
            cout << "True" << endl;
        }
    }
}

bool judge(vector<int> &nums) {
    int n = nums.size();
    int ay = find_max(nums, 0, n - 1);
    if (ay == 0 || ay == n - 1) {
        return false;
    }
    int ax = find_min(nums, 0, ay - 1);
    int az = find_max(nums, ay + 1, n - 1);
    if (nums[ax] < nums[az] && nums[az] < nums[ay]) {
        return true;
    } else {
        return false;
    }
}

int find_max(vector<int> &nums, int start, int end) {
    int res = INT_MIN;
    int location = start;
    for (int i = start; i <= end; i++) {
        if (res < nums[i]) {
            res = nums[i];
            location = i;
        }
    }
    return location;
}

int find_min(vector<int> &nums, int start, int end) {
    int res = INT_MAX;
    int location = start;
    for (int i = start; i <= end; i++) {
        if (res > nums[i]) {
            res = nums[i];
            location = i;
        }
    }
    return location;
}