#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numTrees(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        if (m.find(n) != m.end()) {
            return m[n];
        }
        int sum = 0;
        for(int i = 0; i< n; i++) {
            sum += numTrees(i)*numTrees(n-i-1);
        }
        m[n] = sum;
        return sum;
    }
    vector<TreeNode *> generateTrees(int n) {
        return f(n, 0);
    }
    vector<TreeNode *> f(int n, int start) {
        vector<TreeNode *> res;
        if (n == 0) {
            res.push_back(NULL);
            return res;
        }
        string con_str = con_string(n, start);
        if(m2.find(con_str) != m2.end()) {
            //return m2[con_string(n, start)];
        }
        TreeNode *root;
        for(int i = 1; i <= n; i++) {
            //cout<<root->val<<endl;
            vector<TreeNode *> left_res = f(i-1, start);
            vector<TreeNode *> right_res = f(n-i, start + i);
            for(auto iter = left_res.begin(); iter != left_res.end(); iter++) {
                for(auto iter2= right_res.begin(); iter2 != right_res.end(); iter2++) {
                    root = new TreeNode(start+i);
                    root->left = *iter;
                    root->right = *iter2;
                    cout<<"tree is: ";
                    cout<<root<<" "<<endl;;
                    print_tree(root);
                    cout<<endl;
                    res.push_back(root);
                }
            }
            //cout<<endl;
            for(auto iter = res.begin(); iter != res.end(); iter++) {
                //cout<<(*iter)<<" ";
            }
            //cout<<endl;
        }
        m2[con_str] = res;
        return res;
    }
    string con_string(int n, int start) {
        stringstream ss;
        ss<<n<<start;
        return ss.str();
    }
    void print_tree(TreeNode *root) {
        if (!root) {
            return ;
        }
        cout<<root->val<<" ";
        print_tree(root->left);
        print_tree(root->right);
    }
    unordered_map<int, int> m;
    hash<string> str_hash;
    unordered_map<string, vector<TreeNode *>> m2;
};

int main()
{
    Solution s;
    //cout<<s.numTrees(2);
    s.generateTrees(3);
    return 0;
}
