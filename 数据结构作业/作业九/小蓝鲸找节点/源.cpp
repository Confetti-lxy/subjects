#include <iostream>
#include <vector>
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

public:
    void initialize();
    TreeNode *create();
    int lowestCommonAncestor(TreeNode *root, int p, int q);
};

int main()
{
    Solution solution;
    solution.initialize();
    TreeNode *root = solution.create();
    int n = 0, m = 0;
    cin >> n >> m;
    int ans = solution.lowestCommonAncestor(root, n, m);
    cout << ans << endl;
}

void Solution::initialize()
{
    nums.clear();
    int n = 0;

    while (cin >> n)
    {
        nums.push_back(n);
        if (cin.get() == '\n')
            break;
    }
    // while (scanf("%d", &x) != EOF)
    // {
    //     nums.push_back(x);
    // }
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

int Solution::lowestCommonAncestor(TreeNode *root, int p, int q)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->val == p || root->val == q)
    {
        return 1;
    }
    int x = lowestCommonAncestor(root->left, p, q);
    int y = lowestCommonAncestor(root->right, p, q);
    if (x != -1 && y != -1)
    {
        return root->val;
    }
    else if (x == -1 && y != -1)
    {
        if (y == 1)
        {
            return root->right->val;
        }
        else
        {
            return y;
        }
    }
    else if (x != -1 && y == -1)
    {
        if (x == 1)
        {
            return root->left->val;
        }
        else
        {
            return x;
        }
    }
    else
    {
        return -1;
    }
}