#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0) {
            return res;
        }
        res.push_back(vector<int>({1}));
        for(int i=1; i<numRows; i++) {
            vector<int > tmp;
            tmp.push_back(1);
            for(int j=1; j < static_cast<int>(res[i-1].size()); j++) {
                tmp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        for(int i=1; i < rowIndex; i++) {
            res.push_back(f(rowIndex, i));
        }
        if (rowIndex > 0) {
            res.push_back(1);
        }
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            cout<<*iter<<" ";
        }
        return res;
    }
    int f(int row, int j) {
        stringstream ss;
        ss<<row<<j;
        string s;
        ss>>s;
        if (m.find(s) != m.end()) {
            return m[s];
        }
        if (row < j) {
            return 0;
        }
        if (row == 0 || j == 0) {
            return 1;
        }
        if (j == 1) {
            return row;
        }
        if (j == 2) {
            return (row-1)*(row)/2;
        }
        if (j > row/2) {
            return f(row, row-j);
        }

        m[s] = f(row-1, j-1) + f(row-1,j);
        return m[s];
    }
    unordered_map<string, int> m;
};

int main()
{
    Solution s;
    //s.generate(1);
    s.getRow(2);
    return 0;
}
