#include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int i = 0, j = n-1;
        int res = 0;
        int small = 0;
        for(int k = i+1; k < n;) {
            if (A[k] >= A[i]) {
                int A_min = min(A[k], A[i]);
                res += A_min*(k-i) - A_min - small;
                cout<<i<<" "<<k<<" "<<res<<endl;
                i = k;
                k = i+1;
                small = 0;
            }
            else {
                small += A[k];
                k++;
            }
        }
        small = 0;
        cout<<"j:"<<endl;
        for(int k = j-1; k >=0;) {
            if (A[k] > A[j]) {
                int A_min = min(A[k], A[j]);
                res += A_min*(j-k) - A_min - small;
                cout<<j<<" "<<k<<" "<<res<<endl;
                j = k;
                k = j-1;
                small = 0;
            }
            else {
                small += A[k];
                k--;
            }
        }
        return res;
    }
};

int main()
{
    int A[] = {};
    Solution s;
    cout<<s.trap(A, sizeof(A)/sizeof(A[0]));
    return 0;
}
