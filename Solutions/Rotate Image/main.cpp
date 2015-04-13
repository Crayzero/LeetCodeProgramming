#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int j = 0; n > 1; n-=2,j++) {
            for(int i = 0; i < n-1; i++) {
                int tmp = matrix[j][j+i];
                matrix[j][j+i] = matrix[j+n-i-1][j];
                cout<<j<<" "<<j+i<<":"<<matrix[j][j+i]<<endl;
                matrix[j+n-i-1][j] = matrix[j+n-1][j+n-i-1];
                cout<<j+n-i-1<<" "<<j<<":"<<matrix[j+n-i-1][j]<<endl;
                matrix[j+n-1][j+n-i-1] = matrix[j+i][j+n-1];
                cout<<j+n-1<<" "<<j+n-i-1<<":"<<matrix[j+n-1][j+n-i-1]<<endl;
                matrix[j+i][j+n-1] = tmp;
                cout<<j+i<<" "<<j+n-1<<":"<<matrix[j+i][j+n-1]<<endl;
            }
        }
    }
};

int main()
{
    vector<vector<int> > matrix = {{1}};
    Solution s;
    s.rotate(matrix);
    for(auto iter = matrix.begin(); iter != matrix.end(); iter++) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            cout<<*iter2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
