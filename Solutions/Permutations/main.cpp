#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        if (num.size() == 0) {
            return res;
        }
        for(auto iter = num.begin(); iter != num.end(); iter++) {
            int tmp = *iter;
            num.erase(iter);
            auto rest_res = permute(num);
            if (rest_res.size() > 0 ) {
                for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
                    iter->insert(iter->begin(), tmp);
                    res.push_back(*iter);
                }
            }
            else {
                res.push_back(vector<int>(1, tmp));
            }
            num.insert(iter, tmp);
            for(auto iter = num.begin(); iter != num.end(); iter++) {
                cout<<*iter<<" ";
            }
            cout<<endl;
        }
        return res;
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        if (num.size() == 0) {
            return res;
        }
        vector<int> tmp = num;
        sort(tmp.begin(), tmp.end());
        res = f(tmp);
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
    vector<vector<int> > f(vector<int> &nums) {
        vector<vector<int> > res;
        if (nums.size() == 0) {
            return res;
        }
        auto iter = nums.begin();
        while(iter != nums.end()) {
            int t = *iter;
            cout<<t<<endl;
            nums.erase(iter);
            auto rest_res = f(nums);
            if (rest_res.size() > 0 ) {
                for(auto iter = rest_res.begin(); iter != rest_res.end(); iter++) {
                    iter->insert(iter->begin(), t);
                    res.push_back(*iter);
                }
            }
            else {
                res.push_back(vector<int>(1, t));
            }
            nums.insert(iter,t);
            while(iter != nums.end() &&*iter == t) {
                iter++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,2};
    //auto res = s.permute(nums);
    auto res = s.permuteUnique(nums);
    cout<<"results:-------------------------------"<<endl;
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            cout<<"[ ";
            for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
                cout<<*iter2<<",";
            }
            cout<<" ]";
            cout<<endl;
        }
    return 0;
}
