#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
#define MAXNUMBER 100000001

struct TreeNode {
    long val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(MAXNUMBER), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int backtrack(TreeNode *node, int target);

TreeNode *initialize(int n);

int getanswer(TreeNode *node, int target);

int main() {
    int target = 0, n = 0;
    cin >> target >> n;
    if (n == 0) {
        cout << 0 << endl;
    } else {
        TreeNode *myTree = initialize(n);
        int answer = getanswer(myTree, target);
        cout << answer << endl;
    }
}

int backtrack(TreeNode *node, int target) {
    if (node->val == MAXNUMBER) {
        return 0;
    }
    int ret = 0;
    if (node->val == target) {
        ret++;
    }
    ret += backtrack(node->left, target - node->val);
    ret += backtrack(node->right, target - node->val);
    return ret;
}

TreeNode *initialize(int n) {
    queue < TreeNode * > que;
    int step = 0;
    TreeNode *root = new TreeNode;
    que.push(root);
    while (!que.empty() && step < n) {
        int m = que.size();
        for (int i = 0; i < m && step < n; i++) {
            auto node = que.front();
            que.pop();
            string name;
            cin >> name;
            step++;
            if (name == "null") {
                node->val = MAXNUMBER;
            } else {
                node->val = stoi(name);
            }
            node->left = new TreeNode;
            node->right = new TreeNode;
            que.push(node->left);
            que.push(node->right);
        }
    }
    return root;
}

int getanswer(TreeNode *root, int target) {
    if (root == NULL) {
        return 0;
    }
    int ret = backtrack(root, target);
    ret += getanswer(root->left, target);
    ret += getanswer(root->right, target);
    return ret;
}