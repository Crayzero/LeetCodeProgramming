#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) {
            return 0;
        }
        int *r = new int[triangle.size()];
        for(int i = 0; i < static_cast<int>(triangle.size()); i++) {
            r[i] = triangle[0][0];
            cout<<r[i]<<" ";
        }
        cout<<endl;
        for(int i = 1; i < static_cast<int>(triangle.size()); i++) {
            for(int j = i; j >= 0; j--) {
                if (j == 0) {
                    r[j] = r[j] + triangle[i][j];
                }
                else if (j == i) {
                    r[j] = r[j-1] + triangle[i][j];
                }
                else {
                    r[j] = min(r[j-1] + triangle[i][j], r[j] + triangle[i][j]);
                }
                cout<<r[j]<<" ";
            }
            cout<<endl;
        }
        int res_min = r[0];
        for(int i = 1; i < static_cast<int>(triangle.size()); i++ ) {
            res_min = min(res_min, r[i]);
        }
        return res_min;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> tr = {{2} };
    cout<<s.minimumTotal(tr);
    return 0;
}
