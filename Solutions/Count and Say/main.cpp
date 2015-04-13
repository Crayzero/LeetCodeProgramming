#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 0; i < n-1; i++) {
            res = f(res);
            cout<<res<<endl;
        }
        return res;
    }
    string f(string s) {
        string res;
        for(int i = 0; i < s.size();) {
            stringstream ss;
            int next = i;
            for(; next < s.size() && s[next] == s[i]; next++);
            ss<<next-i;
            string t = ss.str();
            res.insert(res.end(), t.begin(), t.end());
            res.push_back(s[i]);
            i = next;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.countAndSay(4);
    return 0;
}
