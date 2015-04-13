#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) {
            return 0;
        }
        int *dp1 = new int[num.size()];
        int *dp2 = new int[num.size()];
        for(size_t i = 0; i < num.size(); i++) {
            int last_two = i >= 2 ? dp1[i-2] : 0;
            int last_one = i >=1 ? dp2[i-1] : 0;
            dp1[i] = max(last_two, last_one) + num[i];
            last_two = i >= 1 ? dp2[i-1] : 0;
            last_one = i >= 1 ? dp1[i-1] : 0;
            dp2[i] = max(last_two, last_one);
        }
        return max(dp1[num.size()-1], dp2[num.size()-1]);
    }
};
int main()
{
    vector<int> num = {1};
    Solution s;
    cout<<s.rob(num);
    return 0;
}
