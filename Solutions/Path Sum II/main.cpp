#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        cout<<root->val<<" "<<sum<<endl;
        if (root ->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                return true;
            }
            else {
                return false;
            }
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        if (root ->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                res.push_back(vector<int>(1,root->val));
                return res;
            }
            else {
                return res;
            }
        }
        vector<vector<int> > left_res = pathSum(root->left, sum - root->val);
        vector<vector<int> > right_res = pathSum(root->right, sum - root->val);
        for (auto iter = left_res.begin(); iter != left_res.end(); iter++) {
            iter->insert(iter->begin(), root->val);
            res.push_back(*iter);
        }
        for (auto iter = right_res.begin(); iter != right_res.end(); iter++) {
            iter->insert(iter->begin(), root->val);
            res.push_back(*iter);
        }
        return res;
    }
};

int main()
{
    TreeNode *a = new TreeNode(5);
    TreeNode *b = new TreeNode(4);
    TreeNode *c = new TreeNode(8);
    TreeNode *d = new TreeNode(11);
    TreeNode *e = new TreeNode(13);
    TreeNode *f = new TreeNode(4);
    TreeNode *g = new TreeNode(7);
    TreeNode *h = new TreeNode(2);
    TreeNode *i = new TreeNode(1);
    a->left = b;
    a->right = c;
    b->left = d;
    c->left = e;
    c->right = f;
    d->left = g;
    d->right = h;
    f->right = i;
    Solution s;
    cout<<s.hasPathSum(a, 18)<<endl;
    return 0;
}
