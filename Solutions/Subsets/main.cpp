#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> tmp = S;
        sort(tmp.begin(), tmp.end());
        vector<vector<int> > res = f(tmp);
        cout<<"results:-------------------------------"<<endl;
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            cout<<"[ ";
            for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                cout<<*iter2<<",";
            }
            cout<<" ]";
            cout<<endl;
        }
        return res;
    }
    vector<vector<int> > f(vector<int> &S) {
        vector<vector<int> > res;
        if (S.size() == 0) {
            return res;
        }
        int cur = S[0];
        S.erase(S.begin(), S.begin()+1);
        auto rest_res = f(S);
        for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
            for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                cout<<*iter2<<" ";
            }
            cout<<endl;
        }
        if (rest_res.size() > 0 ) {
            for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
                res.push_back(*iter);
                iter->insert(iter->begin(), cur);
                res.push_back(*iter);
            }
        }
        else {
            res.push_back(vector<int>(1, cur));
            res.push_back(vector<int>());
        }
        return res;
    }
};

int main()
{
    vector<int> a = {1,2};
    Solution s;
    s.subsets(a);
    return 0;
}
