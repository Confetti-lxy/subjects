#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    char str;
    TreeNode *left, *right;

    TreeNode(char str) : str(str), left(NULL), right(NULL) {}

    TreeNode(char str, TreeNode *left, TreeNode *right) : str(str), left(left), right(right) {}
};

char judge(string str);

TreeNode *create(string my_str);

void trace(TreeNode *root);

string ans = "";

int main() {
    int n = 0;
    string str;
    cin >> n >> str;
    TreeNode *root = create(str);
    trace(root);
    cout << ans << endl;
}

char judge(string str) {
    int t1 = 0, t2 = 0;
    for (char word: str) {
        if (word == '1') {
            t1++;
        }
        if (word == '0') {
            t2++;
        }
    }
    if (t1 == 0) {
        return 'B';
    } else if (t2 == 0) {
        return 'I';
    } else {
        return 'F';
    }
}

TreeNode *create(string my_str) {
    char s = judge(my_str);
    TreeNode *node = new TreeNode(s);
    if (my_str.length() == 1) {
        return node;
    } else {
        int size = my_str.length() / 2;
        string str1 = my_str.substr(0, size);
        string str2 = my_str.substr(size, my_str.length() - 1);
        node->left = create(str1);
        node->right = create(str2);
        return node;
    }
}

void trace(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    trace(root->left);
    trace(root->right);
    ans += root->str;
}