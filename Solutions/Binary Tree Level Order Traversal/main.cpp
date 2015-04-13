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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) {
            return res;
        }
        build_level(root, res, 0);
        return res;
    }
    void build_level(TreeNode *node, vector<vector<int> > &res, int depth) {
        if (node) {
            if (res.size() <= depth) {
                res.push_back(vector<int> ());
            }
            res[depth].push_back(node->val);
            build_level(node->left, res, depth+1);
            build_level(node->right, res, depth+1);
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
