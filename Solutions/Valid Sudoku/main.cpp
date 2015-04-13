#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++) {
            unordered_map<char, int> m;
            for(int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (m.find(board[i][j]) != m.end()) {
                        return false;
                    }
                    m[board[i][j]] = 1;
                }
            }
        }
        for(int j = 0; j < 9; j++) {
            unordered_map<char, int> m;
            for(int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (m.find(board[i][j]) != m.end()) {
                        return false;
                    }
                    m[board[i][j]] = 1;
                }
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                unordered_map<char, int> m;
                for(int k1 = 0; k1 < 3; k1++) {
                    for(int k2 = 0; k2 < 3; k2++) {
                        if (board[3*i + k1][3*j + k2] != '.') {
                            if(m.find(board[3*i + k1][3*j + k2]) != m.end()) {
                                return false;
                            }
                            m[board[3*i + k1][3*j + k2]] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','7','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    cout<<s.isValidSudoku(board);
    return 0;
}
