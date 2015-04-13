#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int x_size = obstacleGrid.size();
        int y_size = obstacleGrid[0].size();
        if (x_size == 0 || y_size == 0) {
            return 0;
        }
        vector<vector<int>> dp(x_size, vector<int>(y_size,0));
        for(int i = 0; i < x_size && obstacleGrid[i][0] != 1; i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i < y_size && obstacleGrid[0][i] != 1; i++) {
            dp[0][i] = 1;
        }
        for(int i = 1; i < x_size; i++) {
            for(int j = 1; j < y_size; j++) {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
                cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
            }
        }
        return dp[x_size-1][y_size-1];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > grid = {{0,1,0},{1,0,0}};
    //cout<<s.uniquePaths(3,7);
    cout<<s.uniquePathsWithObstacles(grid);
    return 0;
}
