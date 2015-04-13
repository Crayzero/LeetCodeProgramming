class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (root ->left == NULL && root->right == NULL) {
            return 1;
        }
        if (root->left && root->right) {
            return min(minDepth(root->left)+1, minDepth(root->right)+1);
        }
        else {
            return max(minDepth(root->left)+1, minDepth(root->right)+1);
        }
    }
};