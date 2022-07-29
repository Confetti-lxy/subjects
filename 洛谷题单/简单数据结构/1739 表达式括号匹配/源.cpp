#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> my_stack;
    char word;
    cin >> word;
    while (word != '@') {
        if (word == '(') {
            my_stack.push(word);
        } else if (word == ')') {
            if (!my_stack.empty()) {
                if (my_stack.top() == '(') {
                    my_stack.pop();
                } else {
                    my_stack.push(word);
                }
            } else {
                my_stack.push(word);
            }
        }
        cin >> word;
    }
    if (my_stack.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    };
}
