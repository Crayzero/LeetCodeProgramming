#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        return f(res, 2*n);
    }
    vector<string> f(vector<string> &res, int N) {
        if (N == 0) {

            return res;
        }
        int res_size = res.size();
        if (res_size == 0) {
            res.push_back("(");
            m["("] = 1;
            return f(res, N-1);
        }
        while(res_size--) {
            string s = res[0];
            if (m[s] >=0 && m[s] < N) {
                res.push_back(s + "(");
                m[s + "("] = m[s] + 1;
            }
            if (m[s] > 0) {
                res.push_back(s + ")");
                m[s + ")"] = m[s] - 1;
            }
            res.erase(res.begin());
            m.erase(s);
        }
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            cout<<*iter<<" ";
        }
        cout<<endl;
        return f(res, N-1);
    }
    unordered_map<string, int> m;
};

int main()
{
    Solution s;
    vector<string> res;
    res = s.generateParenthesis(5);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<*iter<<" ";
    }
    return 0;
}
