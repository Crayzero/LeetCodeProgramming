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
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return ;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *p = root->left;
        if (p == NULL) {
            return ;
        }
        while(p->right) {
            p = p->right;
        }
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    void printTree(TreeNode *root) {
        while(root) {
            cout<<root->val<<" ";
            root = root->right;
        }
    }
};

int main()
{
    Solution s;
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    a->right = b;
    b->left = c;
    s.flatten(a);
    s.printTree(a);
    return 0;
}
