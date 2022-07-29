#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0, m = 0, a = 0, b = 0, x = 0;
    cin >> n;
    vector<int> nums(n + 1), now(n + 1, 0), ans;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 1) {
            cin >> a >> b;
            int t = b, loc = a;
            while (t > 0) {
                if (now[loc] + t > nums[loc]) {
                    t -= (nums[loc] - now[loc]);
                    now[loc] = nums[loc];
                    loc++;
                } else {
                    now[loc] += t;
                    t = 0;
                }
            }
        } else {
            cin >> a;
            ans.push_back(now[a]);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}