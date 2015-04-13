#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.size() == 0 || L.size() == 0) {
            return res;
        }
        unordered_map<string, int> m;
        for(int i = 0; i < L.size(); i++) {
            if (m.find(L[i]) == m.end()) {
                m[L[i]] = 1;
            }
            else {
                m[L[i]] += 1;
            }
        }
        int L_len = L.size();
        int word_len = L[0].size();
        int total_len = L_len * word_len;
        int left = 0;
        for(int i = 0; i <= S.size() - total_len; i++) {
            unordered_map<string, int> exist;
            int cnt = 0;
            for(int j = 0; j*word_len < total_len; j++) {
                if (i+(j+1)*word_len > S.size()) {
                    return res;
                }
                string sub_str = S.substr(i+j*word_len, word_len);
                cout<<sub_str<<" ";
                if (m.find(sub_str) == m.end()) {
                    break;
                }
                if (exist.find(sub_str) == exist.end()) {
                    exist[sub_str] = 1;
                }
                else {
                    exist[sub_str] += 1;
                }
                if (exist[sub_str] <= m[sub_str]) {
                    cnt++;
                    if (cnt == L_len) {
                        res.push_back(i);
                        break;
                    }
                }
                else {
                    break;
                }
            }
            cout<<endl;
        }
        return res;
    }
};

int main()
{
    string S = "barfoothefoobarman";
    vector<string> L = {"foo", "bar"};
    Solution s;
    vector<int> res = s.findSubstring(S, L);
    for(auto beg = res.begin(); beg != res.end(); beg++) {
        cout<<*beg<<" ";
    }
    return 0;
}
