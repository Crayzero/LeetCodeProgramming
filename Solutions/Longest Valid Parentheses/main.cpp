#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int s_size = s.size();
        if (s_size <= 1) {
            return 0;
        }
        int *dp = new int [s_size];
        for(int i = 0; i < s_size; i++) {
            dp[i] = 0;
        }
        int res = 0;
        for(int i = 1; i < s_size; i++) {
            if (s[i] == ')' && s[i-1] == '(') {
                dp[i] = (i>=2 ? dp[i-2] : 0) + 2;
            }
            else if (dp[i-1] != 0 && s[i] == ')') {
                if (i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (i-dp[i] > 0 && dp[i-dp[i]] != 0) {
                        dp[i] = dp[i] + dp[i-dp[i]];
                    }
                }
            }
            else {
                dp[i] = 0;
            }
            res = max(res, dp[i]);
            for(int i = 0; i < s_size; i++) {
                cout<<dp[i]<<" ";
            }
            cout<<endl;
        }
        return res;
    }
};

int main()
{
    string s1 = "()(())";
    string s2 = "(()())";
    Solution s;
    cout<<s.longestValidParentheses(s1);
    return 0;
}
