#include <iostream>
#include <string>

using namespace std;

int kmp(string source, string target);

int main() {
    string s;
    cin >> s;
    if (s.length() == 0) {
        cout << 0 << endl;
    } else {
        string l(s.rbegin(), s.rend());
        int res = s.length() - kmp(s, l);
        cout << res << endl;
    }
    return 0;
}

int kmp(string source, string target) {
    int n1 = 0;
    int k = -1;
    int next[500001];
    next[0] = -1;
    int size = source.length();
    while (n1 < size) {
        if (k == -1 || source[n1] == source[k]) {
            k++;
            n1++;
            next[n1] = k;
        } else {
            k = next[k];
        }
    }
    int n = source.length(), m = target.length();
    int source_pos = 0, target_pos = 0;
    while (source_pos < n && target_pos < m) {
        if (source_pos == -1 || source[source_pos] == target[target_pos]) {
            source_pos++;
            target_pos++;
        } else {
            source_pos = next[source_pos];
        }
    }
    return source_pos;
}