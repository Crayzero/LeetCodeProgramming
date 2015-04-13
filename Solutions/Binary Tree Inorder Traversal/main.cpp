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
    vector<int> inorderTraversal(TreeNode *root) {
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
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
