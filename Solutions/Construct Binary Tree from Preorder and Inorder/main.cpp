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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return f(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode *f(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end) {
        if (pre_start >= pre_end || in_start >= in_end) {
            return NULL;
        }
        int root_val = preorder[pre_start];
        TreeNode *root = new TreeNode(root_val);
        int i = in_start;
        for(; inorder[i] != root_val; i++);
        int left_dis = i - in_start;
        root->left = f(preorder, pre_start+1, pre_start + 1 + left_dis, inorder, in_start, i);
        root->right = f(preorder, pre_start+1+left_dis, pre_end, inorder, i+1, in_end);
        return root;
    }
};
int main()
{
    return 0;
}
