#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, loc = 0;
    string str, ans;
    cin >> n >> str;
    int weight = str.size() - 1;
    for (int i = weight; i >= 0; i--) {
        if (str[i] != '0') {
            loc = i;
            break;
        }
    }
    for (int i = 0; i <= loc; i++) {
        auto word = str[i];
        if (word != '0') {
            ans += word;
            ans += '*';
            ans += to_string(n);
            ans += '^';
            ans += to_string(weight);;
            if (i != loc) {
                ans += '+';
            }
        }
        weight--;
    }
    cout << ans << endl;
}
