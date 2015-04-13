#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode* > q;
        q.push(root);
        int size = 1;
        int count = 0;
        vector<int > v_breadth;
        while(!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            v_breadth.push_back(p->val);
            size--;
            if (p->left) {
                q.push(p->left);
                count++;
            }
            if (p->right) {
                q.push(p->right);
                count++;
            }
            if (size == 0) {
                size = count;
                count = 0;
                res.insert(res.begin(),v_breadth);
                v_breadth.erase(v_breadth.begin(), v_breadth.end());
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(9);
    TreeNode *c = new TreeNode(20);
    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;
    s.levelOrderBottom(a);
    return 0;
}
