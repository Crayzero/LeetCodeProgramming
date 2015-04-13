class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        TreeNode *root;
        root = f(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return root;
    }
    TreeNode *f(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int post_start, int post_end) {
        if (in_start >= in_end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[post_end-1]);
        int i = in_start;
        for(; i < in_end && inorder[i] != root->val; i++);
        int left_count = i - in_start;
        root->left = f(inorder, in_start, i, postorder, post_start, post_start+left_count);
        root->right = f(inorder, i+1, in_end, postorder, post_start+left_count, post_end-1);
        return root;
    }
};