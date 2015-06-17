#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int x_size = matrix.size();
        if (x_size == 0)
            return 0;
        int y_size = x_size > 0 ? matrix[0].size() : 0;
        if (y_size == 0)
            return 0;
        vector<vector<int>> dp(x_size, vector<int>(y_size, 0));
        for(int i = 0; i < x_size; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            res = max(res, dp[i][0]);
            cout<<i<<":"<<0<<" "<<dp[i][0]<<endl;
        }
        for(int i = 0; i < y_size; i++) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            res = max(res, dp[0][i]);
            cout<<0<<":"<<i<<" "<<dp[0][i]<<endl;
        }
        for(int x = 1; x < x_size; x++) {
            for(int y = 1; y < y_size; y++) {
                if (matrix[x][y] == '1')
                    dp[x][y] = min(dp[x-1][y], min(dp[x][y-1], dp[x-1][y-1])) + 1;
                else
                    dp[x][y] = 0;
                cout<<x<<":"<<y<<" "<<dp[x][y]<<endl;
                res = max(res, dp[x][y]);
            }
        }
        return res*res;
    }
};

int main()
{
    vector<vector<char>> matrix = {{'1','1'},{'1','1'}};
    Solution s;
    cout<<s.maximalSquare(matrix);
    return 0;
}
