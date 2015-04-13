#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        f(n, res);
        cout<<"result is:----------------------------------"<<endl;
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            cout<<*iter<<" ";
        }
        cout<<endl;
        return res;
    }
    void f(int n, vector<int> &res) {
        if (n == 0) {
            res.push_back(0);
            return;
        }
        if (n == 1) {
            res.push_back(0);
            res.push_back(1);
            return;
        }
        f(n-1, res);
        int size = res.size() - 1;
        for(int i = size; i >= 0; i--) {
            int num = res[i] | (1<<(n-1));
            res.push_back(num);
        }
    }
};

int main()
{
    Solution s;
    s.grayCode(0);
    return 0;
}
