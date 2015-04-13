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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        vector<TreeNode *> level_traver;
        vector<int> level_res;
        int size = 1;
        int count = 0;
        int zigzag_order = 0; // 0: left to right, 1: right to left
        level_traver.push_back(root);
        while( !level_traver.empty()) {
            TreeNode *t = level_traver.front();
            level_traver.erase(level_traver.begin());
            size--;
            if (zigzag_order) {
                level_res.insert(level_res.begin(), t->val);
            }
            else {
                level_res.push_back(t->val);
            }
            if (t->left) {
                level_traver.push_back(t->left);
                count++;
            }
            if (t->right) {
                level_traver.push_back(t->right);
                count++;
            }
            if (size == 0) {
                size = count;
                count = 0;
                zigzag_order ^= 1;
                res.push_back(level_res);
                level_res.erase(level_res.begin(), level_res.end());
            }
        }
        print_res(res);
        return res;
    }
    void print_res(const vector<vector<int> > &res) {
        for (auto iter = res.begin(); iter != res.end(); iter++) {
            for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                cout<<*iter2<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(9);
    TreeNode *c = new TreeNode(20);
    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;
    Solution s;
    s.zigzagLevelOrder(a);
    return 0;
}
