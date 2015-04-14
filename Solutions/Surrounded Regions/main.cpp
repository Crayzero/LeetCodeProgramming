#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int x_size = board.size();
        if(x_size == 0) return ;
        int y_size = board[0].size();
        for(int j = 0; j < y_size; j++) {
            if (board[0][j] == 'O') fill_board(board, 0, j);
            if (board[x_size-1][j] == 'O') fill_board(board, x_size-1, j);
        }
        for(int i = 0; i < x_size; i++) {
            if (board[i][0] == 'O') fill_board(board, i, 0);
            if (board[i][y_size-1] == 'O') fill_board(board, i, y_size-1);
        }
        for(int i = 0; i < x_size; i++) {
            for(int j = 0; j < y_size; j++) {
                board[i][j] = board[i][j] == '?' ? 'O' : 'X';
            }
        }
    }
    bool fill_board(vector<vector<char> > &board, int x, int y) {
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        board[x][y] = '?';
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x2 = p.first, y2 = p.second;
            cout<<x2<<" "<<y2<<endl;
            if (x2 > 0 && board[x2-1][y2] == 'O') {
                board[x2-1][y2] = '?';
                q.push(make_pair(x2-1, y2));
            }
            if (x2 < board.size()-1 && board[x2+1][y2] == 'O') {
                board[x2+1][y2] = '?';
                q.push(make_pair(x2+1, y2));
            }
            if (y2 > 0 && board[x2][y2-1] == 'O') {
                board[x2][y2-1] = '?';
                q.push(make_pair(x2, y2-1));
            }
            if (y2 < board[0].size()-1 && board[x2][y2+1] == 'O') {
                board[x2][y2+1] = '?';
                q.push(make_pair(x2, y2+1));
            }
        }
    }
};

int main()
{
    vector<vector<char> > b = {{'O','O','O','X'},{'X','O','O', 'X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution s;
    s.solve(b);
    for(auto beg = b.begin(); beg != b.end(); beg++) {
        for(auto beg2 = beg->begin(); beg2!=beg->end(); beg2++) {
            cout<<*beg2<<" ";
        }
        cout<<endl;
    }

    return 0;
}
