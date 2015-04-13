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
    Solution(): prev(NULL) {}
    bool isValidBST(TreeNode *root) {
        if(!root) {
            return true;
        }
        if (isValidBST(root->left)) {
            if (prev != NULL && root->val <= prev->val) {
                return false;
            }
            prev = root;
            isValidBST(root->right);
        }
    }
    TreeNode *prev;
};

int main()
{
    TreeNode *a = new TreeNode(4);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(6);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(1);
    e->left = d;
    //d->left = b;
    Solution s;
    cout<<s.isValidBST(e);
    return 0;
}
