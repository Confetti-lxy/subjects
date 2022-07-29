#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int cal(vector<int> &values, int loc, long long max_val);

int main() {
    int n = 0, max_val = 0;
    long long val_sum = 0;
    cin >> n >> max_val;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        val_sum += (values[i] / n) + 1;
    }
    int left = 1, right = val_sum;
    while (left <= right) {
        int middle = (left + right) >> 1;
        int key = cal(values, middle, max_val);
        if (key == 1) {
            left = middle + 1;
        } else if (key == -1) {
            right = middle - 1;
        } else {
            left = middle;
            break;
        }
    }
    while (cal(values, left, max_val) != 1) {
        left--;
    }
    cout << left + 1 << endl;
}

int cal(vector<int> &values, int loc, long long max_val) {
    long long val_sum = 0;
    int n = values.size();
    for (int i = 0; i < n; i++) {
        int x = values[i] / loc, y = values[i] % loc;
        val_sum += ((y == 0) ? x : x + 1);
    }
    if (val_sum > max_val) {
        return 1;
    } else if (val_sum == max_val) {
        return 0;
    } else {
        return -1;
    }
}