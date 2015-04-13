#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0 || target < A[0]) {
            return 0;
        }
        if (target > A[n-1]) {
            return n;
        }
        int left = 0, right = n-1;
        while(left < right-1) {
            int mid = (left + right)/2;
            if (target == A[mid]) {
                return mid;
            }
            if (target < A[mid]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return A[left] == target ? left: left + 1;
    }
};

int main()
{
    int A[] = {};
    Solution s;
    cout<<s.searchInsert(A, sizeof(A)/sizeof(A[0]), 4);
    return 0;
}
