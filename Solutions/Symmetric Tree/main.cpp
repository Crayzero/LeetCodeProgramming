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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        return recursive_slove(nodes);
        //return non_recursive_slove(root);
    }
    bool recursive_slove(vector<TreeNode *> &nodes) {
        vector<TreeNode *> nodes2;
        cout<<nodes.size()<<endl;
        if (isSymmetric(nodes)) {
            int null_count = 0;
            for(auto iter = nodes.begin(); iter != nodes.end(); iter++) {
                if (*iter != NULL) {
                    cout<<(*iter)->val<<" ";
                    nodes2.push_back((*iter)->left);
                    nodes2.push_back((*iter)->right);
                }
                else {
                    null_count++;
                }
            }
            cout<<endl;
            if (null_count == static_cast<int>(nodes.size())) {
                return true;
            }
            return recursive_slove(nodes2);
        }
        return false;
    }
    bool non_recursive_slove(TreeNode *root) {
        vector<TreeNode *> s;
        s.push_back(root);
        while(!s.empty()) {
            int size = s.size();
            int null_count = size;
            while(size > 0) {
                TreeNode *p = s.front();
                s.erase(s.begin());
                if (p) {
                    cout<<p->val<<" ";
                    s.push_back(p->left);
                    s.push_back(p->right);
                }
                else {
                    null_count--;
                }
                size--;
            }
            cout<<endl;
            if (null_count == 0) {
                return true;
            }
            if (!isSymmetric(s)) {
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(vector<TreeNode *> &nodes) {
        auto j = nodes.size()-1;
        decltype(j) i = 0;
        for(;i<j; i++, j--) {
            if ((nodes[i] != NULL && nodes[j] != NULL) && (nodes[i]->val == nodes[j]->val)) {
                continue;
            }
            if (nodes[i] == NULL && nodes[j] == NULL) {
                continue;
            }
            return false;
        }
        if (i >= j) {
            return true;
        }
        return false;
    }
};

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(2);
    TreeNode *d = new TreeNode(3);
    TreeNode *e = new TreeNode(4);
    TreeNode *f = new TreeNode(4);
    TreeNode *g = new TreeNode(3);
    a->left = b;
    a->right = c;
    //b->left = d;
    b->right = e;
    //c->left = f;
    c->right = g;
    Solution s ;
    cout<<s.isSymmetric(a);
    return 0;
}
