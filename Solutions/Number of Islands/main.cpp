#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int cnt = 0;
        stack<pair<int, int> > s;
        int x, y;
        int x_size = grid.size();
        if(x_size == 0) {
            return 0;
        }
        int y_size = grid[0].size();
        while(find_1(grid, x, y)) {
            cnt++;
            s.push(make_pair(x, y));
            while(!s.empty()) {
                pair<int, int> p = s.top();
                s.pop();
                int x = p.first;
                int y = p.second;
                cout<<x<<" "<<y<<endl;
                grid[x][y] = '?';
                char left = x-1 >= 0 ? grid[x-1][y] : '0';
                char right = x+1 < x_size ? grid[x+1][y] : '0';
                char top = y-1 >= 0 ? grid[x][y-1] : '0';
                char bottom = y+1 < y_size ? grid[x][y+1] : '0';
                if (left == '1') {
                    s.push(make_pair(x-1, y));
                }
                if (right == '1') {
                    s.push(make_pair(x+1, y));
                }
                if (top == '1') {
                    s.push(make_pair(x, y-1));
                }
                if (bottom == '1') {
                    s.push(make_pair(x, y+1));
                }
            }
            cout<<endl;
        }
        for(int i = 0; i < x_size; i++) {
            for(int j = 0; j < y_size; j++) {
                if (grid[i][j] == '?') {
                    grid[i][j] = '1';
                }
            }
        }
        return cnt;
    }
    bool find_1(vector<vector<char> > &grid, int &x, int &y) {
        for(size_t i = 0; i < grid.size(); i++) {
            for(size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    x = i, y = j;
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char> > grid = {{'1', '1', '1'},
                                  {'0', '1', '0'},
                                  {'1', '1', '1'}};
    Solution s;
    cout<<s.numIslands(grid);
    return 0;
}
