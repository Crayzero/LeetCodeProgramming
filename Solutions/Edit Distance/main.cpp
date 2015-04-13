#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1_size = word1.size();
        int w2_size = word2.size();
        vector<vector<int> > dp(w1_size+1, vector<int>(w2_size+1,0));
        for(int i = 0; i <= w1_size; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= w2_size; j++) {
            dp[0][j] = j;
        }
        for(int i = 1; i <= w1_size; i++) {
            for(int j = 1; j <= w2_size; j++) {
                cout<<i<<" "<<j<<" ";
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if (i != j) {
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                    }
                    else {
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) +1;
                    }
                }
                cout<<dp[i][j]<<endl;
            }
        }
        return dp[w1_size][w2_size];
    }
};

int main()
{
    string w1 = "algorithm";
    string w2 = "altruistic";
    Solution s;
    cout<<s.minDistance(w1, w2);
    return 0;
}
