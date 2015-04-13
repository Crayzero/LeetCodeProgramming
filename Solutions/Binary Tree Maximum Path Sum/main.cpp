#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int max_sum = root->val;
        find_max(root, max_sum);
        return max_sum;
    }
    int find_max(TreeNode *root, int &max_sum) {
        if (root == NULL) {
            return 0;
        }
        int left = find_max(root->left, max_sum);
        int right = find_max(root->right, max_sum);
        int sum = root->val + max(left, 0) + max(right, 0);
        if (sum > max_sum) {
            max_sum = sum;
        }
        return root->val + max(left, max(right, 0));
    }
};

int main()
{
    TreeNode *a = new TreeNode(-1);
    TreeNode *b = new TreeNode(-2);
    TreeNode *c = new TreeNode(-3);
    TreeNode *d = new TreeNode(-4);
    a->left = b;
    a->right = c;
    b->left = d;
    Solution s;
    cout<<s.maxPathSum(a)<<endl;
    return 0;
}
