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
    void recoverTree(TreeNode *root) {
        prev = p1 = p2 = NULL;
        f(root);
        cout<<p1->val<<" "<<p2->val<<endl;
        swap(p1->val, p2->val);
    }
    void f(TreeNode *root) {
        if (!root) {
            return ;
        }
        f(root->left);
        if (prev != NULL) {
            cout<<prev->val<<" "<<root->val<<endl;
            if (prev->val > root->val) {
                if (p1 == NULL) {
                    p1 = prev;
                }
                p2 = root;
            }
        }
        prev = root;
        f(root->right);
    }
    TreeNode *prev, *p1, *p2;
};

int main()
{
    TreeNode *a = new TreeNode(4);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(6);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(3);
    e->left = d;
    d->left = b;
    Solution s;
    s.recoverTree(e);
    return 0;
}
