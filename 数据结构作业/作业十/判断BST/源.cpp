#include <iostream>
#include <vector>

using namespace std;

bool judge(vector<int> &nums, int start, int loc);

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    cout << judge(nums, 1, n) << endl;
    return 0;
}

bool judge(vector<int> &nums, int start, int loc) {
    if (start >= loc) {
        return true;
    }
    int location = start;
    while (nums[location] < nums[loc]) {
        location++;
    }
    for (int i = location; i < loc; i++) {
        if (nums[i] < nums[loc]) {
            return false;
        }
    }
    return judge(nums, start, location - 1) && judge(nums, location, loc - 1);
}