#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        cout<<left_depth<<" "<<right_depth<<endl;
        if (abs(right_depth-left_depth) <= 1) {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }
    int depth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (m.find(root) != m.end()) {
            return m[root];
        }
        m[root] = max(depth(root->left)+1, depth(root->right)+1);
        return m[root];
    }
    unordered_map<TreeNode*, int> m;
};
int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    Solution s;
    //a->left = b;
    //a->right = c;
    //b->left = d;
    //d->left = e;
    cout<<s.isBalanced(a)<<endl;
    return 0;
}
