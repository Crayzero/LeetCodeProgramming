#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left,*right, *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return ;
        }
        while(root->left) {
            TreeLinkNode *p = root;
            while(p) {
                if (p->left) {
                    p->left->next = p->right;
                }
                if (p->next) {
                    p->right->next = p->next->left;
                }
                p = p->next;
            }
            root = root->left;
        }
    }
    void connect2(TreeLinkNode *root) {
        if (root == NULL) {
            return ;
        }
        queue<TreeLinkNode *> q;
        q.push(root);
        int size = 1;
        int count = 0;
        while(!q.empty()) {
            TreeLinkNode *p = q.front();
            q.pop();
            size--;
            if (size) {
                p->next = q.front();
                cout<<p->val<<"->"<<q.front()->val<<endl;
            }
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
            }
        }
    }
};

int main()
{
    TreeLinkNode *a = new TreeLinkNode(1);
    TreeLinkNode *b = new TreeLinkNode(2);
    TreeLinkNode *c = new TreeLinkNode(3);
    TreeLinkNode *d = new TreeLinkNode(4);
    TreeLinkNode *e = new TreeLinkNode(5);
    TreeLinkNode *f = new TreeLinkNode(6);
    a->left = b;
    //a->right = c;
    //b->left = d;
    //b->right = e;
    //d->left = f;
    //c->left = f;
    Solution s;
    s.connect2(a);
    return 0;
}
