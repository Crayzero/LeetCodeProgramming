#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int one_forward = 1;
        int two_forward = 1;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        for(int i = 2; i <= n; i++) {
            int tmp = one_forward + two_forward;
            one_forward = two_forward;
            two_forward = tmp;
        }
        return two_forward;
    }
};

int main()
{
    Solution s;
    cout<<s.climbStairs(6);
    return 0;
}
