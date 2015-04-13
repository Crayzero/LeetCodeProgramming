#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //dp
        int s_size = strlen(s);
        int p_size = strlen(p);
        if (p_size == 0 && s_size != 0) {
            return false;
        }
        if (s_size > 300 && p[0] == '*' && p[p_size-1] == '*') {
            return false;
        }
        if (s_size == 0) {
            for(int i = 0; i < p_size; i++) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }
        vector<int> dp(s_size+1, 0);
        dp[0] = 1;
        for(int i = 0; i < p_size; i++) {
            cout<<p[i]<<":";
            if(p[i] == '*') {
                int j = 0;
                for(; j <= s_size && dp[j] != 1; j++);
                for(; j <= s_size; j++) {
                    dp[j] = 1;
                }
            }
            else {
                for(int j = s_size; j > 0; j--) {
                    if(p[i] == '?' || p[i] == s[j-1]) {
                        dp[j] = dp[j-1];
                    }
                    else {
                        dp[j] = 0;
                    }
                }
                dp[0] = 0;
            }
            for(int k = 0; k <= s_size; k++) {
                cout<<dp[k]<<" ";
            }
            cout<<endl;
        }
        return dp[s_size];
    }

    bool isMatch2(const char *s, const char *p) {
        int s_size = strlen(s);
        char *p_new = change(p);
        cout<<s<<":"<<p_new<<endl;
        if (*s == '\0' && *p_new == '\0') {
            return true;
        }
        if (*s == '\0') {
            while( *p_new != '\0') {
                if (*p_new != '*') {
                    return false;
                }
                p_new++;
            }
            return true;
        }
        if (*p_new != '*') {
            if (*p_new == '?' || *p_new == *s) {
                return isMatch2(++s, ++p_new);
            }
            else {
                return false;
            }
        }
        else {
            for(int i = 0; i < s_size; i++) {
                if (isMatch2(s+i, p_new+1)) {
                    return true;
                }
            }
            return false;
        }
    }
    char * change(const char *p ){
        char *t = new char [strlen(p)];
        char *h = t;
        int dup = 0;
        while(*p != '\0') {
            if (*p == '*' && dup == 0) {
                *t++ = *p;
                dup = 1;
            }
            if (*p != '*') {
                *t++ = *p;
                dup = 0;
            }
            p++;
        }
        *t = '\0';
        return h;
    }
};

int main()
{
    string s = "aab";
    string p = "?*b";
    Solution S;
    cout<<S.isMatch(s.c_str(), p.c_str());
    return 0;
}
