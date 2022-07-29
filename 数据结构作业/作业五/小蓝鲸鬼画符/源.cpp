#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct spell {
    int start;
    int end;
};

bool cmd(spell a, spell b);

void my_sort(vector <spell> &a);

int main() {
    int n = 0;
    cin >> n;
    vector <spell> my_spell(n), res;
    for (int i = 0; i < n; i++) {
        cin >> my_spell[i].start >> my_spell[i].end;
    }
    my_sort(my_spell);
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (my_spell[i].start <= my_spell[index].end) {
            my_spell[index].end = max(my_spell[index].end, my_spell[i].end);
        } else {
            res.push_back(my_spell[index]);
            index = i;
        }
    }
    res.push_back(my_spell[index]);
    int size = res.size();
    for (int i = 0; i < size; i++) {
        cout << res[i].start << " " << res[i].end << endl;
    }
}

bool cmd(spell a, spell b) {
    if ((a.start < b.start) || (a.start == b.start && a.end < b.end))
        return true;
    else
        return false;
}

void my_sort(vector <spell> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (cmd(a[j], a[j - 1])) {
                swap(a[j - 1], a[j]);
            }
        }
    }
}