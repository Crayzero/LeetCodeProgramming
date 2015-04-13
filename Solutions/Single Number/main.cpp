#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            res ^= A[i];
        }
        return res;
    }
    int singleNumber2(int A[], int n) {
        int ones = 0, twos = 0, xthrees = 0;
        for(int i = 0; i < n; ++i) {
            twos |= (ones & A[i]);
            ones ^= A[i];
            xthrees = ~(ones & twos);
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }
};

int main()
{
    int A[] = {1,2,2};
    Solution s;
    cout<<s.singleNumber(A, sizeof(A)/sizeof(A[0]));
    return 0;
}
