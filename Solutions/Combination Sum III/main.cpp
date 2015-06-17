#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> used;
        return f(k, n, used);
    }

    vector<vector<int>> f(int k, int n, vector<int> &used) {
        vector<vector<int>> res;
        if (k == 0 && n == 0) {
            res.push_back(used);
            return res;
        }
        int last = used.empty() ? 0 : used.back();
        for(int i = last + 1; i <= 9; i++) {
            used.push_back(i);
            vector<vector<int>> tmp;
            if (n - i >= 0)
                tmp = f(k-1, n-i, used);
            else {
                used.pop_back();
                break;
            }
            for(auto iter = tmp.begin(); iter != tmp.end(); iter++)
                res.push_back(*iter);
            used.pop_back();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.combinationSum3(4, 20);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<"[";
        for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            cout<<*iter2<<",";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}
