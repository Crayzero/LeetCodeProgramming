#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int x_size = dungeon.size();
        if (x_size == 0) {
            return 0;
        }
        int y_size = dungeon[0].size();
        vector<vector<int> > dp(x_size, vector<int>(y_size, 0));
        for(int i = x_size-1; i >= 0; i--) {
            for(int j = y_size-1; j >= 0; j--) {
                if (i == x_size-1 && j == y_size-1) {
                    dp[i][j] = 1- dungeon[i][j];
                }
                else if (i == x_size-1) {
                    dp[i][j] = dp[i][j+1] - dungeon[i][j];
                }
                else if( j == y_size-1) {
                    dp[i][j] = dp[i+1][j] - dungeon[i][j];
                }
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                }
                dp[i][j] = dp[i][j] > 0 ? dp[i][j] : 1;
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[0][0];
    }
};

int main()
{
    vector<vector<int> > dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    Solution s;
    cout<<s.calculateMinimumHP(dungeon);
    return 0;
}
