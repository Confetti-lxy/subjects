#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> nums;
    vector <vector<int>> ans;
    int loc = 0;

public:
    void initialize(int n);

    TreeNode *create();

    vector <vector<int>> levelOrder(TreeNode *root);
};

int main() {
    int n = 0;
    cin >> n;
    Solution solution;
    solution.initialize(n);
    TreeNode *my_root = solution.create();
    vector <vector<int>> ans = solution.levelOrder(my_root);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void Solution::initialize(int n) {
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    loc = 0;
    return;
}

TreeNode *Solution::create() {
    if (nums[loc] == -1) {
        return NULL;
    }
    TreeNode *root = new TreeNode(nums[loc]);
    ++loc;
    root->left = create();
    ++loc;
    root->right = create();
    return root;
}

vector <vector<int>> Solution::levelOrder(TreeNode *root) {
    if (root == NULL) {
        return ans;
    }
    queue < TreeNode * > que;
    que.push(root);
    int flag = 0;
    while (!que.empty()) {
        vector<int> res;
        int n = que.size();
        for (int i = 0; i < n; i++) {
            TreeNode *node = que.front();
            que.pop();
            res.push_back(node->val);
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        if (flag % 2 != 0) {
            reverse(res.begin(), res.end());
        }
        ans.push_back(res);
        flag++;
    }
    return ans;
}