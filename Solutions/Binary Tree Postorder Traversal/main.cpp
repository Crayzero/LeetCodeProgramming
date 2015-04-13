#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        s.push_back(root);
        vector <int > res;
        if (root == NULL) {
            return res;
        }
        while(!s.empty()) {
            TreeNode *t_root = s.back();
            if (t_root->left == NULL && t_root->right == NULL) {
                res.push_back(t_root->val);
                s.pop_back();
                while(!s.empty()) {
                    TreeNode *t_p = s.back();
                    if (t_p->left == t_root || t_p->right == t_root) {
                        res.push_back(t_p->val);
                        s.pop_back();
                        t_root = t_p;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                if (t_root->right != NULL) {
                    s.push_back(t_root->right);
                }
                if (t_root->left != NULL) {
                    s.push_back(t_root->left);
                }
            }
        }
        return res;
    }
    vector<TreeNode * > s;
};

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    a->right = b;
    a->left = d;
    b->left = c;
    d->left = e;
    d->right = f;
    b->right = g;
    Solution s;
    vector<int> res = s.postorderTraversal(a);
    for(auto beg = res.begin(); beg != res.end(); beg++) {
        cout<<*beg<<" ";
    }
    cout<<endl;
    return 0;
}
