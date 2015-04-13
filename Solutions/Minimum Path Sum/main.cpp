#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int x_size = grid.size();
        int y_size = grid[0].size();
        vector<vector<int> > dp(x_size, vector<int> (y_size, 0));
        if (x_size == 0 || y_size == 0) {
            return 0;
        }
        dp[0][0] = grid[0][0];
        for(int i = 1; i < x_size; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < y_size; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < x_size; i++) {
            for(int j = 1; j < y_size; j++) {
                cout<<i<<" "<<j<<":"<<dp[i][j-1]<<" "<<dp[i-1][j]<<endl;
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
            }
        }
        return dp[x_size-1][y_size-1];
    }
};

int main()
{
    vector<vector<int> > grid = {{1,7,4,3,2,2,2,9,2,6}, {3,6,6,1,0,5,9,6,3,8},{1,5,4,5,3,8,7,2,5,6}, {5,7,6,9,0,8,1,4,7,5}};
    Solution s;
    cout<<s.minPathSum(grid);
    return 0;
}
