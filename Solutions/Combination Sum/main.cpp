#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return f(candidates, target);
    }
    vector<vector<int> > f(vector<int > &candidates, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        for(auto iter = candidates.begin(); iter != candidates.end() && *iter <= target; iter++) {
            if (target == *iter) {
                tmp.push_back(*iter);
                res.push_back(tmp);
            }
            else {
                vector<vector<int> > res_rest = f(candidates, target- *iter);
                if (res_rest.size()) {
                    for(auto iter2 = res_rest.begin(); iter2 != res_rest.end(); iter2++) {
                        if (*iter <= iter2->front()) {
                            iter2->insert(iter2->begin(), *iter);
                            res.push_back(*iter2);
                        }
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        return f2(num, target, 0);
    }
    vector<vector<int> > f2(vector<int> &num, int target, int start) {
        vector<vector<int> > res;
        vector<int> tmp;
        for(int i = start; i < num.size() && num[i] <= target;) {
            int next = i;
            for(; next < num.size() && num[next] == num[i]; next++);
            for(int j = 1; j <= next-i; j++) {
                vector<int> tmp(j, num[i]);
                if (target == num[i]*j) {
                    res.push_back(tmp);
                }
                vector<vector<int> > res_rest = f2(num, target- num[i] * j, next);
                if (res_rest.size()) {
                    for(auto iter2 = res_rest.begin(); iter2 != res_rest.end(); iter2++) {
                        iter2->insert(iter2->begin(), tmp.begin(), tmp.end());
                        res.push_back(*iter2);
                    }
                }
            }
            i = next;
        }
        return res;
    }
};

int main()
{
    vector<int> candidates = {1,1,1,2,2};
    Solution s;
    vector<vector<int> > res = s.combinationSum2(candidates, 5);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            cout<<*iter2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
