#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() == 0) {
            return ;
        }
        int i = num.size()-1;
        for(; i > 0 && num[i] <= num[i-1]; i--);
        if (i == 0) {
            reverse(num.begin(), num.end());
        }
        else {
            int j = num.size()-1;
            for(;num[j] <= num[i-1]; j--);
            int t = num[j];
            num.erase(num.begin() + j);
            num.insert(num.begin() + i - 1, t);
            sort(num.begin()+i, num.end());
        }
    }
};

int main()
{
    vector<int> num = {4,6,5,2,1};
    Solution s;
    s.nextPermutation(num);
    for(auto iter = num.begin(); iter != num.end(); iter++) {
        cout<<*iter<<" ";
    }
    return 0;
}
