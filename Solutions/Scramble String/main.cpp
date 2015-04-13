#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int s_size = s2.size();
        if (s_size == 0) {
            return true;
        }
        vector<vector<vector<int> > > dp(s_size, vector<vector<int>>(s_size, vector<int>(s_size+1, 0)));
        for(int i = 0; i < s_size; i++) {
            for(int j = 0; j < s_size; j++) {
                if (s2[i] == s1[j]) {
                    dp[i][j][1] = 1;
                    cout<<i<<" "<<i<<" "<<j<<endl;
                }
            }
        }
        for(int i = 2; i<= s_size; i++) {
            for(int j = 0; j <= s_size-i; j++) {
                for(int k = 0; k <= s_size-i; k++) {
                    for(int t = 1; t < i; t++) {
                        dp[j][k][i] |= (dp[j][k][t] && dp[j+t][k+t][i-t]) || (dp[j][k+i-t][t] && dp[j+t][k][i-t]);
                        if (dp[j][k][i]) {
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][s_size];
    }
};

int main()
{
    string s1("abcd");
    string s2("abcd");
    Solution s;
    cout<<s.isScramble(s1,s2)<<endl;
    return 0;
}
