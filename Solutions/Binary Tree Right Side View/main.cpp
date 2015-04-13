#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        q.push(root);
        int cnt = 1;
        int size = 0;
        while(!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            cnt--;
            if (t->left) {q.push(t->left); size++;}
            if (t->right) {q.push(t->right); size++;}
            if (cnt == 0) {
                res.push_back(t->val);
                cnt = size;
                size = 0;
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
    TreeNode *d = new TreeNode(5);
    TreeNode *e = new TreeNode(4);
    a->left = b;
    vector<int> res;
    Solution s;
    res = s.rightSideView(a);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<*iter<<" ";
    }
    return 0;
}
