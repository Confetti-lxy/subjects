#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> book;

void printTree(TreeNode *root);

vector<int> input(int n);

TreeNode *init(vector<int> &input, int left, int right);

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums = input(n);
    TreeNode *root = init(nums, 0, n - 1);
    printTree(root);
}

void printTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    queue < TreeNode * > que;
    que.push(root);
    vector<int> ans;
    while (!que.empty()) {
        int n = que.size();
        for (int i = 0; i < n; i++) {
            auto node = que.front();
            que.pop();
            if (!node) {
                ans.push_back(-1);
            } else {
                ans.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
        }
    }
    int index = ans.size() - 1;
    while (index >= 0 && ans[index] == -1) {
        index--;
    }
    for (int i = 0; i <= index; i++) {
        cout << ans[i] << " ";
    }
}

vector<int> input(int n) {
    vector<int> res(n);
    book.resize(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

TreeNode *init(vector<int> &input, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int index = left, num = input[left];
    for (int i = left; i <= right; i++) {
        if (input[i] > num && book[i] == 1) {
            num = input[i];
            index = i;
        }
    }
    TreeNode *node = new TreeNode(input[index]);
    book[index] = 0;
    node->left = init(input, left, index - 1);
    node->right = init(input, index + 1, right);
    return node;
}