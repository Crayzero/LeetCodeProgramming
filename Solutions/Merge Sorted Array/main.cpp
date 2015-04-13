#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int A_size = m+n;
        while(m>0 && n>0) {
            if (A[m-1] >= B[n-1]) {
                A[A_size-1] = A[m-1];
                m--;
            }
            else {
                A[A_size-1] = B[n-1];
                n--;
            }
            A_size--;
        }
        for(;n;n--,A_size--) {
            A[A_size-1] = B[n-1];
        }
    }
};

int main()
{
    Solution s;
    int A[10] = {1,2};
    int B[2] = {2,5};
    s.merge(A, 0, B, 0);
    for(int i = 0; i< 5; i++) {
        cout<<A[i]<<" ";
    }
    return 0;
}
