#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0) {
            return false;
        }
        int *dp = new int[s.size()];

        for(string::size_type i = 0; i < s.size(); i++) {
            dp[i] = 0;
        }
        if (dict.find(s.substr(0,1)) != dict.end()) {
            dp[0] = 1;
        }
        for (string::size_type i = 1; i < s.size(); i++) {
            string subs = s.substr(0, i+1);
            cout<<subs<<"\t";
            if (dict.find(subs) != dict.end()) {
                dp[i] = 1;
            }
            for(string::size_type j = 0; j < i; j++) {
                if(dp[j] == 1) {
                    subs = s.substr(j+1, i-j);
                    if (dict.find(subs) != dict.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            cout<<dp[i]<<endl;
        }
        if (dp[s.size()-1]) {
            delete [] dp;
            return true;
        }
        delete [] dp;
        return false;
    }
    vector<string> wordBreak2(string s, unordered_set<string> &dict) {
        unordered_map<int, pair<int, vector<int> > > m;
        vector<string> res;
        if (s.size() == 0) {
            return res;
        }
        for(string::size_type i = 0; i < s.size(); i++) {
            m[i] = make_pair(0, vector<int>());
        }
        if (dict.find(s.substr(0,1)) != dict.end()) {
            m[0].first = 1;
            m[0].second.push_back(0);
        }
        else {
            m[0].first = 0;
            m[0].second.push_back(-1);
        }
        for (string::size_type i = 1; i < s.size(); i++) {
            string subs = s.substr(0, i+1);
            cout<<subs<<"\t";
            if (dict.find(subs) != dict.end()) {
                m[i].first = 1;
                m[i].second.push_back(-1);
            }
            for(string::size_type j = 0; j < i; j++) {
                if(m[j].first == 1) {
                    subs = s.substr(j+1, i-j);
                    if (dict.find(subs) != dict.end()) {
                        m[i].first = 1;
                        m[i].second.push_back(j);
                    }
                }
            }
            cout<<m[i].first<<"\t";
            for(auto beg = m[i].second.begin(); beg != m[i].second.end(); beg++) {
                cout<<*beg<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        if (s.size() == 1 && m[0].first == 1) {
            res.push_back(s);
            return res;
        }
        if(m[s.size()-1].first == 1) {
            return get_all_string(m, s.size()-1, s);
        }
        else {
            return res;
        }
    }
    vector<string> get_all_string(unordered_map<int, pair<int, vector<int> > > &m, int from, string &str) {
        vector<int> from_v = m[from].second;
        string s;
        vector<string > v_t;
        if (from == 0) {
            v_t.push_back(str.substr(0,1));
            return v_t;
        }
        for(auto beg = from_v.begin(); beg != from_v.end(); beg++) {
            string subs;
            if (*beg >= 0) {
                subs = str.substr(*beg+1, from - *beg);
            }
            else {
                subs = str.substr(0, from + 1);
            }
            cout<<subs<<endl;
            vector<string > t = get_all_string(m, *beg, str);
            if (t.size() == 0) {
                v_t.push_back(subs);
            }
            for(auto beg2 = t.begin(); beg2 != t.end(); beg2++) {
                s = *beg2 + " " + subs;
                v_t.push_back(s);
            }
        }
        return v_t;
    }

};

int main()
{
    Solution solution;
    string s = "leeta";
    unordered_set<string> dict = {"leet", "code", "a"};
    //cout<<solution.wordBreak(s, dict)<<endl;
    vector<string > res;
    string s2 = "a";
    unordered_set<string> dict2 = {};
    res = solution.wordBreak2(s2, dict2);
    for(auto beg = res.begin(); beg != res.end(); beg++) {
        cout<<*beg<<endl;
    }
    return 0;
}
