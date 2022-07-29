#include <iostream>
#include <string>

using namespace std;

int num[100001];

int main() {
    int n = 0;
    while (scanf("%d", &num[n]) != EOF)
        n++;
    int *ans = new int[n + 1];
    ans[n] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (num[j] > num[i]) {
                ans[i] = j - i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}