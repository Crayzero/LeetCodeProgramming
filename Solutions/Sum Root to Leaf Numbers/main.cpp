#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left{NULL}, right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        vector<int> res = f(root, 0);
        int sum = 0;
        for(auto beg = res.begin(); beg != res.end(); beg++) {
            cout<<*beg<<endl;
            sum += *beg;
        }
        return sum;
    }
    vector<int> f(TreeNode *root, int sum) {
        vector<int > t;
        sum = sum*10 + root->val;
        if (root ->left == NULL && root->right == NULL) {
            t.push_back(sum);
            return t;
        }
        vector<int> left_v;
        if (root->left) {
            left_v = f(root->left, sum);
        }
        vector<int> right_v;
        if (root->right) {
            right_v = f(root->right, sum);
        }
        for(auto beg = left_v.begin(); beg != left_v.end(); beg++) {
            t.push_back(*beg);
        }
        for(auto beg = right_v.begin(); beg != right_v.end(); beg++) {
            t.push_back(*beg);
        }
        return t;
    }
};

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    a->left = b;
    a->right = c;
    b->left = d;
    d->right = e;
    Solution s;
    int res = s.sumNumbers(a);
    cout<<res<<endl;
    return 0;
}
