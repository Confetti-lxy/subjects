#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    char word;
    TreeNode *left, *right;

    TreeNode(char word) : word(word), left(NULL), right(NULL) {}

    TreeNode(char word, TreeNode *left, TreeNode *right) : word(word), left(left), right(right) {}
};

TreeNode *createTree(string str1, string str2);

void trace(TreeNode *root);

string ans = "";

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    TreeNode *root = createTree(str1, str2);
    trace(root);
    cout << ans << endl;
}

TreeNode *createTree(string str1, string str2) {
    if (str1.length() == 0) {
        //        cout << -1 << endl;
        return NULL;
    }
    char start = str2[str2.length() - 1];
    TreeNode *node = new TreeNode(start);
    if (str1.length() == 1) {
        //        cout << 0 << endl;
        return node;
    } else {
        int loc = -1;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] == start) {
                loc = i;
                break;
            }
        }
        string str3 = str1.substr(0, loc);
        string str4 = str1.substr(loc + 1, str1.length() - 1);
        string str5 = str2.substr(0, loc);
        string str6 = str2.substr(loc, str2.length() - 1 - loc);
        if (loc == str2.length() - 1) {
            str6 = "";
        }
        //        cout << loc << " " << str3 << " " << str4 << " " << str5 << " " << str6 << endl;
        node->left = createTree(str3, str5);
        node->right = createTree(str4, str6);
        return node;
    }
}

void trace(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    ans += root->word;
    trace(root->left);
    trace(root->right);
}
