#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return ;
        }
        bool first_row_zero = false;
        bool first_col_zero = false;
        for(int i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                first_row_zero = true;
                break;
            }
        }
        for(int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }
        for(int x = 0; x < row; x++) {
            for(int y = 0; y < col; y++) {
                if (matrix[x][y] == 0) {
                    matrix[x][0] = 0;
                    matrix[0][y] = 0;
                }
            }
        }
        for(int x = 1; x < row; x++) {
            if (matrix[x][0] == 0) {
                for(int y = 1; y < col; y++) {
                    matrix[x][y] = 0;
                }
            }
        }
        for(int y = 1; y < col; y++) {
            if (matrix[0][y] == 0) {
                for(int x = 1; x < row; x++) {
                    matrix[x][y] = 0;
                }
            }
        }
        if (first_row_zero) {
            for(int y = 0; y < col; y++) {
                matrix[0][y] = 0;
            }
        }
        if (first_col_zero) {
            for(int x = 0; x < row; x++) {
                matrix[x][0] = 0;
            }
        }
    }
};
int main()
{
    vector<vector<int> > matrix = {{1,1,0,1},{1,1,1,1}, {0,1,1,1}};
    Solution s;
    s.setZeroes(matrix);
    for(auto iter = matrix.begin(); iter != matrix.end(); iter++) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            cout<<*iter2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
