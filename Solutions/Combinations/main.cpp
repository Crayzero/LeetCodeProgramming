#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        auto res = f(1,n, k);
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
    vector<vector<int> > f(int start, int end, int k) {
        vector<vector<int> > res;
        if (start > end || k == 0) {
            return res;
        }
        for(int i = start; i <= end; i++) {
            if (end - i < k-1) {
                break;
            }
            auto i_res = f(i+1, end, k-1);
            if (i_res.size() > 0) {
                for(auto iter = i_res.begin(); iter != i_res.end(); iter++) {
                    iter->insert(iter->begin(), i);
                    res.push_back(*iter);
                }
            }
            else {
                res.push_back(vector<int>(1,i));
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.combine(5,2);
    return 0;
}
