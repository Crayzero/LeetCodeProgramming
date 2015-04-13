class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pos = 0;
        vector<TreeNode*> stack;
        while(stack.size()>0 || root !=NULL) {
            if (root){
                stack.push_back(root);
                root = root->left;
            }else{
                root = stack.back();
                stack.pop_back();
                v.push_back(root->val);
                root = root->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pos < v.size();
    }

    /** @return the next smallest number */
    int next() {
        return v[pos++];
    }
private:
        vector<int> v;
        int pos;
};