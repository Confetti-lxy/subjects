#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

int main() {
    int n = 0, count = 0;
    cin >> n;
    vector<int> nums(n, -1);
    unordered_map<int, int> my_map;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        my_map[nums[i]] = i;
    }
    for (int i = 0; i < n - 1; i += 2) {
        if (fabs(nums[i] - nums[i + 1]) != 1) {
            if (nums[i] % 2 == 0) {
                int loc = my_map[nums[i] + 1];
                my_map[nums[i + 1]] = loc;
                my_map[nums[i] + 1] = i + 1;
                swap(nums[i + 1], nums[loc]);
            } else {
                int loc = my_map[nums[i] - 1];
                my_map[nums[i + 1]] = loc;
                my_map[nums[i] - 1] = i + 1;
                swap(nums[i + 1], nums[loc]);
            }
            count++;
        }
    }
    cout << count << endl;
}