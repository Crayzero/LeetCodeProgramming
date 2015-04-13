#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int x_size = matrix.size();
        if (x_size == 0) {
            return false;
        }
        int y_size = matrix[0].size();
        if (y_size == 0) {
            return false;
        }
        int x_left = 0, x_right = x_size-1;
        if (target < matrix[x_left][0] ||  target > matrix[x_right][y_size-1]) {
            return false;
        }
        while(x_left <= x_right) {
            cout<<x_left<<" "<<x_right<<endl;
            if (x_left == x_right) {
                break;
            }
            if (target >= matrix[x_right][0]) {
                x_left = x_right;
                break;
            }
            int x_mid = (x_left + x_right)/2;
            if (target < matrix[x_mid][0]) {
                x_right = x_mid-1;
            }
            else {
                x_left = x_mid;
                x_right = x_right-1;
            }
        }
        cout<<"y axis:"<<endl;
        int y_left = 0, y_right = y_size-1;
        while(y_left <= y_right) {
            int y_mid = (y_left + y_right)/2;
            cout<<y_left<<" "<<y_right<<endl;
            if (target == matrix[x_left][y_mid] ) {
                return true;
            }
            if (target > matrix[x_left][y_mid]) {
                y_left = y_mid + 1;
            }
            else {
                y_right = y_mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > m = {{1}};
    Solution s;
    cout<<s.searchMatrix(m, 1);
    return 0;
}
