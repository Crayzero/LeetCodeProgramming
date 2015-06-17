#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int level = 0;
        for(TreeNode *p = root; p; level++, p = p->left);
        if (level <= 1)
            return pow(2, level-1);
        int cnt = 0;
        int cur_level = 1;
        cnt = pow(2, level - cur_level - 1);
        int tot = 0;
        while(1) {
            if (cnt == 1) {
                return pow(2, level-1) -1 + tot + (root->left ? 1 : 0) + (root->right ? 1 : 0);
            }
            TreeNode *left = root->left;
            TreeNode *tmp = left;
            cur_level++;
            if (cur_level == level)
                tmp = root;
            for(int i = cur_level; i < level-1 && tmp; ++i) {
                tmp = tmp->right;
            }
            cout<<tmp->val<<endl;
            if (tmp == NULL)
                return pow(2, level - 1) + tot -1;
            if (tmp->left == NULL && tmp->right == NULL) {
                cnt /= 2;
                root = root->left;
            }
            else if (tmp->right == NULL) {
                tot += cnt - 1;
                return pow(2, level - 1) -1 + tot;
            }
            else {
                tot += cnt;
                cnt /= 2;
                root = root->right;
            }
            cout<<" "<<tot<<endl;
        }
        cout<<cnt<<endl;
        return pow(2, level-1) - 1 + cnt;
    }
};

int main()
{
    TreeNode *a1 = new TreeNode(1);
    TreeNode *a2 = new TreeNode(2);
    TreeNode *a3 = new TreeNode(3);
    TreeNode *a4 = new TreeNode(4);
    TreeNode *a5 = new TreeNode(5);
    TreeNode *a6 = new TreeNode(6);
    TreeNode *a7 = new TreeNode(7);
    TreeNode *a8 = new TreeNode(8);
    TreeNode *a9 = new TreeNode(9);
    TreeNode *a10 = new TreeNode(10);
    TreeNode *a11 = new TreeNode(11);
    TreeNode *a12 = new TreeNode(12);
    TreeNode *a13 = new TreeNode(13);
    TreeNode *a14 = new TreeNode(14);
    TreeNode *a15 = new TreeNode(15);
    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    a3->left = a6;
    a3->right = a7;
    a4->left = a8;
    //a4->right = a9;
    //a5->left = a10;
    //a5->right = a11;
    //a6->left = a12;
    //a6->right = a13;
    //a7->left = a14;
    //a7->right = a15;
    Solution s;
    cout<<s.countNodes(a1);
    return 0;
}
