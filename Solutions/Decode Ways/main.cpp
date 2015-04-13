#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int s_size = s.size();
        if (s_size == 0 || s[0] == '0') {
            return 0;
        }
        int *dp = new int [s_size];
        dp[0] = 1;
        for(int i=1; i < s_size; i++) {
            int a = (s[i-1]-'0')*10 + s[i]-'0';
            if (s[i] == '0') {
                if (a <= 26 && a > 0) {
                    dp[i] = i > 1?dp[i-2]: 1;
                }
                else {
                    return 0;
                }
            }
            else {
                if (a>10 && a <=26) {
                    dp[i] = i > 1? dp[i-1] + dp[i-2] : dp[i-1] + 1;
                }
                else {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[s_size-1];
    }
};

int main()
{
    Solution s;
    string test_s = "123";
    cout<<s.numDecodings(test_s)<<endl;
    return 0;
}
