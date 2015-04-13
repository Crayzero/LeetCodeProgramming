#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        if (digits.size() == 0) {
            return res;
        }
        int add = 1;
        for(int i = digits.size()-1; i >= 0; i--) {
            res.insert(res.begin(), (digits[i] + add) %10);
            if (digits[i] + add >= 10) {
                add = 1;
            }
            else {
                add = 0;
            }
        }
        if (add == 1) {
            res.insert(res.begin(), 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> digs = {9,9,0,9,9};
    vector<int> res;
    res = s.plusOne(digs);
    for(auto iter = res.begin(); iter != res.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
