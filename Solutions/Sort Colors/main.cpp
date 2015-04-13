#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int k = 0;
        for(int j = n-1; k < j;) {
            for(; k < n && A[k] == 0; k++);
            for(; j >= 0 && A[j] != 0; j--);
            if (k < j) {
                swap(A[k], A[j]);
            }
            else {
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        for(int i = k, j = n-1; i < j;) {
            for(; i < n && A[i] == 1; i++);
            for(; j >= 0 && A[j] != 1; j--);
            if (i < j) {
                swap(A[i], A[j]);
            }
        }
        for(int i = 0; i < n; i++) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int A[] = {2,0,0};
    Solution s;
    s.sortColors(A, sizeof(A)/sizeof(A[0]));
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
