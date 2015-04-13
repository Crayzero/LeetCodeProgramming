#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string > res = f(s, 0, 4);
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            cout<<*iter<<endl;
        }
        return f(s, 0, 4);
    }
    vector<string> f(string s, int start, int cnt) {
        vector<string> res;
        int size = s.size();
        if (size - start > cnt*3 || size-start < cnt) {
            return res;
        }
        if (cnt == 1) {
            string one = s.substr(start);
            if (one.size() == 1) {
                res.push_back(one);
            }
            else  if (one[0] != '0'){
                if (one.size() < 3 || one <= max_IP) {
                    res.push_back(one);
                }
            }
            return res;
        }
        vector<string> res2 = f(s, start+1, cnt-1);
        for(auto iter = res2.begin(); iter != res2.end(); iter++) {
            res.push_back(s.substr(start,1) + "." + *iter);
        }
        if (s[start] != '0') {
            res2 = f(s, start+2, cnt-1);
            for(auto iter = res2.begin(); iter != res2.end(); iter++) {
                res.push_back(s.substr(start,2) + "." + *iter);
            }
        }
        string one = s.substr(start, 3);
        if (one <= max_IP && one[0] != '0') {
            res2 = f(s, start+3, cnt-1);
            for(auto iter = res2.begin(); iter != res2.end(); iter++) {
                res.push_back(s.substr(start,3) + "." + *iter);
            }
        }
        return res;
    }
    const string max_IP = "255";
};

int main()
{
    Solution s;
    s.restoreIpAddresses("0010001");
    return 0;
}
