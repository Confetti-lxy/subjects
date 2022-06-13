#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<int> nums;
    int loc = 0;
    vector<vector<int>> ans;
    void level_order(TreeNode *root);

public:
    void initialize(int n);
    TreeNode *create();
    int treasure(TreeNode *root);
};

int main()
{
    int n = 0;
    cin >> n;
    Solution solution;
    solution.initialize(n);
    TreeNode *my_root = solution.create();
    int ans = solution.treasure(my_root);
    cout << ans << endl;
}

void Solution::initialize(int n)
{
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    loc = 0;
    return;
}

TreeNode *Solution::create()
{
    if (nums[loc] == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(nums[loc]);
    ++loc;
    root->left = create();
    ++loc;
    root->right = create();
    return root;
}

void Solution::level_order(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        vector<int> res;
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            res.push_back(node->val);
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
        }
        ans.push_back(res);
    }
    return;
}

int Solution::treasure(TreeNode *root)
{
    ans.clear();
    level_order(root);
    int n = ans.size();
    return ans[n - 1][0];
}