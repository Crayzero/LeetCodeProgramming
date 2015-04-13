#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> tmp = S;
        sort(tmp.begin(), tmp.end());
        vector<vector<int> > res = f(tmp);
        cout<<"results:-------------------------------"<<endl;
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                cout<<*iter2<<" ";
            }
            cout<<endl;
        }
        return res;
    }
    vector<vector<int> > f(vector<int> &S) {
        vector<vector<int> > res;
        if (S.size() == 0) {
            return res;
        }
        int i;
        for(i=1; i < S.size() && S[i] == S[0]; i++);
        int cur = S[0];
        S.erase(S.begin(), S.begin() + i);
        auto rest_res = f(S);
        for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
            for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                cout<<*iter2<<" ";
            }
            cout<<endl;
        }
        for(int j = 0; j <= i; j++) {
            if (rest_res.size() > 0 ) {
                for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
                    vector<int> t(j, cur);
                    cout<<j<<" "<<cur<<endl;
                    t.insert(t.end(), iter->begin(), iter->end());
                    res.push_back(t);
                }
            }
            else {
                res.push_back(vector<int>(j, cur));
            }
        }
        return res;
    }
};

int main()
{
    vector<int> s = {};
    Solution sol;
    sol.subsetsWithDup(s);
    return 0;
}
