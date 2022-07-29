#include <iostream>

using namespace std;

void quicksort(int *arr, int first, int last);

void swap(int &a, int &b);

int main() {
    int n = 0, m = 0;
    cin >> m >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << arr[n - m] << endl;
}

void quicksort(int *arr, int first, int last) {
    if (first >= last) {
        return;
    }
    int left = first, right = last;
    int key = left;
    while (left < right) {
        while (left < right && arr[right] >= arr[key]) {
            right--;
        }
        while (left < right && arr[left] <= arr[key]) {
            left++;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    int meet = left;
    swap(arr[key], arr[left]);
    quicksort(arr, first, meet - 1);
    quicksort(arr, meet + 1, last);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}