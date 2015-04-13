#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; i++) {
            while(A[i] != i+1 && A[i] <= n && A[i] > 0) {
                if (A[i] == A[A[i]-1]) {
                    break;
                }
                cout<<A[i]<<"<->"<<A[A[i]-1]<<endl;
                swap(A[i], A[A[i]-1]);
            }
        }
        for(int i = 0; i < n; i++) {
            if (A[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};

int main()
{
    int A[] = {1,2,2,2,4,5};
    Solution s;
    cout<<s.firstMissingPositive(A, sizeof(A)/sizeof(A[0]));
    return 0;
}
