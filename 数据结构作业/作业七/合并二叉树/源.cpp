#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
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

static int loc = 0;

TreeNode *creatTree(vector<int> arr);

void print(TreeNode *head);

TreeNode *mergeTrees(TreeNode *head1, TreeNode *head2);

int main() {
    int n1 = 0;
    vector<int> nums1;
    while (cin >> n1) {
        nums1.push_back(n1);
        char s = cin.get();
        if (s == '\n') {
            break;
        }
    }
    int n2 = 0;
    vector<int> nums2;
    while (cin >> n2) {
        nums2.push_back(n2);
        char s2 = cin.get();
        if (s2 == '\n') {
            break;
        }
    }

    TreeNode *head1 = creatTree(nums1);
    loc = 0;
    TreeNode *head2 = creatTree(nums2);
    TreeNode *head3 = mergeTrees(head1, head2);
    print(head3);
}

TreeNode *creatTree(vector<int> arr) {
    TreeNode *head = new TreeNode;
    if (arr[loc] == -1) {
        loc++;
        delete head;
        head = NULL;
        return NULL;
    }
    head = new TreeNode;
    head->val = arr[loc++];
    head->left = creatTree(arr);
    head->right = creatTree(arr);
    return head;
}

void print(TreeNode *head) {
    if (head == NULL) {
        cout << -1 << " ";
        return;
    }
    cout << head->val << " ";
    print(head->left);
    print(head->right);
    return;
}

TreeNode *mergeTrees(TreeNode *head1, TreeNode *head2) {
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }
    TreeNode *head3 = new TreeNode;
    if (head1 != NULL && head2 == NULL) {
        head3->val = head1->val;
        head3->left = mergeTrees(head1->left, head2);
        head3->right = mergeTrees(head1->right, head2);
    } else if (head1 == NULL && head2 != NULL) {
        head3->val = head2->val;
        head3->left = mergeTrees(head1, head2->left);
        head3->right = mergeTrees(head1, head2->right);
    } else {
        head3->val = head1->val + head2->val;
        head3->left = mergeTrees(head1->left, head2->left);
        head3->right = mergeTrees(head1->right, head2->right);
    }

    return head3;
}