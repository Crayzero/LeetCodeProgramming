#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, int> m;
        unordered_map<string, string> m2;
        for(auto iter = strs.begin(); iter != strs.end(); iter++) {
            string s_tmp = *iter;
            sort(s_tmp.begin(), s_tmp.end());
            if (m.find(s_tmp) == m.end()) {
                m[s_tmp] = 1;
                m2[s_tmp] = *iter;
            }
            else {
                if (m[s_tmp] == 1) {
                    res.push_back(m2[s_tmp]);
                }
                m[s_tmp] += 1;
                res.push_back(*iter);
            }
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"tea","and","ate","eat","dan"};
    Solution s;
    vector<string> res;
    res = s.anagrams(strs);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<*iter<<" ";
    }
    return 0;
}
