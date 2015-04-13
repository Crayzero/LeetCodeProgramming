#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        if (num.size() < 4) {
            return res;
        }
        for(int i = 0; i < num.size()-3; i++) {
            for(int j = i+1; j < num.size()-2; j++) {
                int target_2 = target - num[i] - num[j];
                int left = j + 1, right = num.size()-1;
                while(left < right) {
                    int sum_t = num[left] + num[right];
                    if (sum_t < target_2) {
                        while(left+1 < num.size() && num[left+1] == num[left]) left++;
                        left++;
                    }
                    else if (sum_t > target_2) {
                        while(right-1 >= 0 && num[right-1] == num[right]) right--;
                        right--;
                    }
                    else {
                        res.push_back(vector<int> ({num[i], num[j], num[left], num[right]}));
                        while(left+1 < num.size() && num[left+1] == num[left]) left++;
                        while(right-1 >= 0 && num[right-1] == num[right]) right--;
                        left = left < num.size()-1 ? left+1 : num.size()-1;
                        right = right > 0? right - 1 : 0;
                    }
                }
                while(j+1 < num.size() && num[j+1] == num[j]) j++;
            }
            while(i+1 < num.size() && num[i+1] == num[i] ) i++;
        }
        return res;
    }
    vector<vector<int> > fourSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> two_sum;
        unordered_map<int, vector<pair<int, int> > > m;

        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); i++) {
            for(int j = i+1; j < num.size(); j++) {
                if(m.find(num[i] + num[j]) == m.end()) {
                    vector<pair<int, int> > tmp;
                    tmp.push_back(make_pair(i, j));
                    m[num[i] + num[j]] = tmp;
                    two_sum.push_back(num[i] + num[j]);
                }
                else {
                    m[num[i] + num[j]].push_back(make_pair(i, j));
                }
            }
        }
        for(int i = 0; i < num.size()-3;) {
            for(int j = i+1; j < num.size()-2;) {
                if (m.find(target - num[i] - num[j]) != m.end()) {
                    auto t = m[target - num[i] - num[j]];
                    bool first = true;
                    for(auto iter = t.begin(); iter != t.end(); iter++) {
                        if (iter->first > j) {
                            vector<int> last;
                            if (res.size()) last = res.back();
                            if (first || num[iter->first] != last[2]) {
                                vector<int> tmp = {num[i], num[j]};
                                tmp.push_back(num[iter->first]);
                                tmp.push_back(num[iter->second]);
                                res.push_back(tmp);
                                first = false;
                            }
                        }
                    }
                }
                int t = j + 1;
                for(; t < num.size() && num[t] == num[j]; t++);
                j = t;
            }
            int t = i + 1;
            for(; t < num.size() && num[t] == num[i]; t++);
            i = t;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> num = {1, 0, -1, 0, -2, 2};
    vector<vector<int> > res = s.fourSum(num, 0);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            cout<<*iter2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
