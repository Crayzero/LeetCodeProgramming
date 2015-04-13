#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i, j;
        int len = n;
        i = j = 0;
        for(j = 1;j < n; j++) {
            if (A[j] != A[i]) {
                A[++i] = A[j];
            }
            else {
                len--;
            }
        }
        return len;
    }
    int removeDuplicates2(int A[], int n) {
        int i , j;
        int len = n;
        i = j = 0;
        int last_val = A[0];
        int cnt = 1;
        for (j=1; j < n; j++) {
            if (A[j] == last_val) {
                cnt++;
                if (cnt < 3) {
                    A[++i] = A[j];
                }
                else {
                    len--;
                }
            }
            else {
                A[++i] = A[j];
                last_val = A[j];
                cnt = 1;
            }
        }
        return len;
    }
};

int main()
{
    int A[] = {1,1,1,1,3,3};
    Solution s;
    //cout<<s.removeDuplicates(A, sizeof(A)/sizeof(A[0]));
    cout<<s.removeDuplicates2(A, sizeof(A)/sizeof(A[0]));
    return 0;
}
