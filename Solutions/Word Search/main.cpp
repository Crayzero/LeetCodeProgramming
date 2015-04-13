#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<int>> used (board.size(), vector<int> (board[0].size(), 0));
        for(int x = 0; x < board.size(); x++) {
            for(int y = 0; y < board[x].size(); y++) {
                if (board[x][y] == word[0]) {
                    if (f(board, word, 1, x, y, used)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool f(vector<vector<char> > &board, string &word, int start, int last_x, int last_y, vector<vector<int> > used) {
        if (word.size() == start) {
            return true;
        }
        used[last_x][last_y] = 1;
        cout<<last_x<<","<<last_y<<" "<<board[last_x][last_y]<<endl;
        char top = last_x ? board[last_x-1][last_y] : 0;
        char bottom = last_x < board.size()-1 ? board[last_x+1][last_y] : 0;
        char left = last_y ? board[last_x][last_y-1] : 0;
        char right = last_y < board[0].size()-1 ? board[last_x][last_y+1] : 0;
        if (top != 0 && top == word[start] && used[last_x-1][last_y] == 0) {
            if (f(board, word, start+1, last_x-1, last_y, used)) {
                return true;
            }
        }
        if (bottom != 0 && bottom == word[start] && used[last_x+1][last_y] == 0) {
            if (f(board, word, start+1, last_x+1, last_y, used)) {
                return true;
            }
        }
        if (left != 0 && left == word[start] && used[last_x][last_y-1] == 0) {
            if (f(board, word, start+1, last_x, last_y-1, used)) {
                return true;
            }
        }
        if (right != 0 && right == word[start] && used[last_x][last_y+1] == 0) {
            if (f(board, word, start+1, last_x, last_y+1, used)) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char> > board = {{'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'}};
    Solution s;
    cout<<s.exist(board, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
    return 0;
}
