#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        f(board);
    }
    bool f(vector<vector<char> > &board) {
        int x = 0, y = 0;
        for(x = 0; x < board.size(); x++) {
            for(y = 0; y < board[0].size(); y++) {
                if (board[x][y] == '.') {
                    break;
                }
            }
            if (board[x][y] == '.') {
                break;
            }
        }
        cout<<x<<","<<y<<endl;
        if (x == 9 && y == 9) {
            return true;
        }
        for(char i = '1'; i <= '9'; i++) {
            if (check(i, x, y, board)) {
                board[x][y] = i;
                if (f(board)) {
                    return true;
                }
                board[x][y] = '.';
            }
        }
        return false;
    }
    bool check(int i, int x, int y, const vector<vector<char> > &board) {
        for(int j = 0; j < 9; j++) {
            if (board[x][j] == i || board[j][y] == i) {
                return false;
            }
        }
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if (board[3*(x/3)+j][3*(y/3)+k] == i) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char > >  board = {{'5','3','.', '.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.', '9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}
                                    };
    Solution s;
    s.solveSudoku(board);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
