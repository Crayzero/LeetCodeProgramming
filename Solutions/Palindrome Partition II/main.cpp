class Solution {
public:
    int minCut(string s) {
        const int size = s.size();
        if (size <= 1) {
            return 0;
        }
        vector<vector<int>> dp(size, vector<int>(size,1));
        int *res = new int[size];
        res[0] = 0;
        for(int i = 1; i < size; i++) {
            res[i] = res[i-1] + 1;
            dp[0][i] = s[0] == s[i]? dp[1][i-1] : 0;
            if(dp[0][i] == 1) {
                res[i] = 0;
            }
            for(int j = 1; j < i; j++) {
                dp[j][i] = s[j] == s[i] ? dp[j+1][i-1] : 0;
                if (dp[j][i] == 1) {
                    int min_j_i = res[j-1] + 1;
                    if (res[i] > min_j_i) {
                        res[i] = min_j_i;
                    }
                }
            }
        }
        return res[size-1];
    }
};