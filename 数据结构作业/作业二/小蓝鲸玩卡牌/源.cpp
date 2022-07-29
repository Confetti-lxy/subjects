#include <iostream>

using namespace std;

int find(int num[], long n, long long target);

int main() {
    long n;
    long long target;
    cin >> n;
    int *number = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }
    cin >> target;
    cout << find(number, n, target);
}

int find(int num[], long n, long long target) {
    int left = 0, right = 0;
    long long sum = num[0];
    long count = 1000001;
    for (int i = 1; i < n; i++) {
        sum += num[i];
        right = i;
        if (sum >= target) {
            while (sum >= target) {
                sum -= num[left];
                left++;
            }
            count = (count > right - left + 2) ? (right - left + 2) : count;
        }
    }
    return (count < 1000001) ? count : 0;
}