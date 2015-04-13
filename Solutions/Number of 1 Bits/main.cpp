#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    cout<<s.hammingWeight(11);
    return 0;
}
