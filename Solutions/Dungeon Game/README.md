该题使用DP求解时，不能从start开始，因为在某一个时刻dp[i][j],它的值不能直接有dp[i-1][j]和dp[i][j-1]决定。因为除了最小的health point影响了结果，当前的health也影响了结果。
因此反向思考，从end到start，最小的时候必然到end为1，这样逆序向左走和向上走，dp(i,j)表示到end需要的最小health point, dp(i,j)的下一步不是向下就是向右，而且与上一个点的health point无关，因为上一个点的health point就是dp(i+1,j), 因此dp(i,j)的值完全依赖于dp(i+1, j)和dp(i,j+1)的值。
动态规划的递推是由已知解向下一个解递推，有start开始的dp(i,j)与从end开始的dp(i,j)不是对称的。