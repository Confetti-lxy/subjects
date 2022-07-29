#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    string ans, str;
    cin >> n >> ans;
    for (int i = 1; i < n; i++) {
        cin >> str;
        int x = ans.find(str[0]);
        ans.erase(x, 1);
        ans.insert(x, str);
    }
    for (char word: ans) {
        if (word != '*') {
            cout << word;
        }
    }
    cout << endl;
}
