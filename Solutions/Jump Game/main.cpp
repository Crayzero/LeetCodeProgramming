#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0;
        if (n <= 1) {
            return true;
        }
        int m = A[0];
        while(i < n) {
            if (A[i] == 0) {
                return false;
            }
            for(int j = 0; j <= A[i]; j++) {
                m = max(A[i+j] + i+j, m);
                if (m >= n-1) {
                    return true;
                }
            }
            i = m;
        }
        return false;
    }
};

int main()
{
    int A[] = {3,2,1,0,4};
    Solution s;
    cout<<s.canJump(A, sizeof(A)/sizeof(A[0]));
    return 0;
}
