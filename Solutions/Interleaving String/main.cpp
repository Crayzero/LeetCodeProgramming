#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto s1_size = s1.size();
        auto s2_size = s2.size();
        auto s3_size = s3.size();
        if (s1_size + s2_size != s3_size) {
            return false;
        }
        vector<vector<int>> dp(s1_size+1, vector<int>(s2_size+1,0));
        dp[0][0] = 1;
        for(decltype(s2_size) i = 1; i <= s2_size; i++) {
            if (s2.substr(0, i) == s3.substr(0,i)) {
                dp[0][i] = 1;
            }
        }
        for(decltype(s1_size) i = 1; i <= s1_size; i++) {
            if (s1.substr(0, i) == s3.substr(0,i)) {
                dp[i][0] = 1;
            }
        }
        for(decltype(s1_size) i = 1; i <= s1_size; i++) {
            for(decltype(s2_size) j = 0; j <= s2_size; j++) {
                cout<<s3.substr(0,i+j)<<" ";
                if (s1[i-1] == s3[i+j-1]) {
                    dp[i][j] |= dp[i-1][j];
                }
                if (s2[j-1] == s3[i+j-1]) {
                    dp[i][j] |= dp[i][j-1];
                }
                cout<<dp[i][j]<<endl;
            }
        }
        return dp[s1_size][s2_size];
    }
};

int main()
{
    string s1 = "ac";
    string s2 = "ac";
    string s3 = "ac";
    Solution s;
    cout<<s.isInterleave(s1, s2, s3)<<endl;
    return 0;
}
