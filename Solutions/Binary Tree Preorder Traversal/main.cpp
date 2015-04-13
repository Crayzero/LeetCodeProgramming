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
    vector<int> midorderTraversal(TreeNode *root) {
        vector<int > res;
        vector<TreeNode *> s;
        if (root == NULL) {
            return res;
        }
        s.push_back(root);
        while(!s.empty()) {
            TreeNode *t_root = s.back();
            if (t_root->left != NULL) {
                s.push_back(t_root->left);
            }
            else {
                res.push_back(t_root->val);
                s.pop_back();
                if (t_root ->right != NULL) {
                    s.push_back(t_root->right);
                }
                else {
                    while(!s.empty()) {
                        TreeNode *t_p = s.back();
                        res.push_back(t_p->val);
                        s.pop_back();
                        if (t_p->right) {
                            s.push_back(t_p->right);
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        vector<TreeNode *> s;
        s.push_back(root);
        while(!s.empty()) {
            TreeNode *t = s.back();
            res.push_back(t->val);
            s.pop_back();
            if (t->right) {
                s.push_back(t->right);
            }
            if(t->left) {
                s.push_back(t->left);
            }
        }
        return res;
    }
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
//    b->left = c;
//    d->left = e;
    d->right = f;
//    b->right = g;
    Solution s;
    vector<int> res = s.preorderTraversal(a);
    for(auto beg = res.begin(); beg != res.end(); beg++) {
        cout<<*beg<<" ";
    }
    cout<<endl;
    return 0;
}
