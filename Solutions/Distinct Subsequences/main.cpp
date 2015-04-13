#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int s_size = S.size();
        int t_size = T.size();
        if (s_size < t_size) {
            return 0;
        }
        if (s_size == t_size) {
            if (s_size == 0) {
                return 0;
            }
            return S == T ? 1:0;
        }
        vector<vector<int>> dp(t_size+1, vector<int>(s_size+1,0));
        for(int i = 0; i <= s_size; i++) {
            dp[0][i] = 1;
        }
        for(int i = 1; i <= t_size; i++) {
            cout<<i<<":";
            for(int j = i; j <= s_size; j++) {
                if (S[j-1] == T[i-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[t_size][s_size];
    }
};

int main()
{
    string S("ccc");
    string T("c");
    Solution s;
    cout<<s.numDistinct(S,T)<<endl;
    return 0;
}
