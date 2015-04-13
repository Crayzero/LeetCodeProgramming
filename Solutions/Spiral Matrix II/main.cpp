#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int top = 0;
        int bottom = matrix.size()-1;
        if (bottom < 0) {
            return res;
        }
        int left = 0;
        int right = matrix[0].size()-1;
        int x = 0, y = 0;
        int direction = 0; //0: right, 1: down, 2: left, 3: up
        int size = matrix.size() * matrix[0].size();
        while(size--) {
            cout<<direction<<" "<<x<<" "<<y<<endl;
            res.push_back(matrix[x][y]);
            if (y == right && direction == 0) {
                direction = 1;
                top++;
            }
            if (x == bottom && direction == 1) {
                direction = 2;
                right--;
            }
            if (y == left && direction == 2) {
                direction = 3;
                bottom--;
            }
            if (x == top && direction == 3) {
                direction = 0;
                left++;
            }
            switch(direction) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
            }
        }
        return res;
    }
    vector<vector<int> > generateMatrix(int n) {
        int direction = 0;
        vector<vector<int> > res(n, vector<int>(n,0));
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int size = n*n;
        int x=0, y=0;
        for(int i = 1; i <= size; i++) {
            res[x][y] = i;
            if (y == right && direction == 0) {
                direction = 1;
                top++;
            }
            if (x == bottom && direction == 1) {
                direction = 2;
                right--;
            }
            if (y == left && direction == 2) {
                direction = 3;
                bottom--;
            }
            if (x == top && direction == 3) {
                direction = 0;
                left++;
            }
            switch(direction) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int> > matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    Solution s;
    /*vector<int> res = s.spiralOrder(matrix);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;*/
    matrix = s.generateMatrix(0);
    for(auto iter = matrix.begin(); iter != matrix.end(); iter++) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            cout<<*iter2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
