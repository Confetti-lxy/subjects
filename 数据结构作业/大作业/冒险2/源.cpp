#include <iostream>

using namespace std;

int search(int *arr, int start, int end, int val);

int main() {
    int n = 0, m = 0, x = 0;
    cin >> m >> n;
    int *arr = new int[n];
    int *ans = new int[n];
    for (int i = 0; i < n; i++) {
        int t = i + 1;
        int location = ((t % m == 0) ? (t / m) : ((t / m) + 1));
        cin >> arr[i];
        int loc = search(arr, 0, i - 1, arr[i]);
        int temp = arr[i];
        for (int j = i - 1; j >= loc; j--) {
            arr[j + 1] = arr[j];
        }
        arr[loc] = temp;
        cout << arr[i - location + 1] << " ";
    }
    cout << endl;
}

int search(int *arr, int start, int end, int val) {
    int left = start, right = end;
    while (left <= right) {
        int middle = (left + right) >> 1;
        if (arr[middle] > val) {
            right = middle - 1;
        } else if (arr[middle] < val) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return left;
}