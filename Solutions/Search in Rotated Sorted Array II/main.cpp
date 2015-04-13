#include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0) {
            return false;
        }
        return f(A, 0, n, target);
    }
    bool f(int A[], int start, int end, int target) {
        int mid = (start + end)/2;
        cout<<start<<" "<<end<<endl;
        if (start >= end) {
            return false;
        }
        if (A[mid] == target) {
            return true;
        }
        if (A[mid] == A[start] && A[mid] == A[end-1]) {
            return f(A, start, mid, target) || f(A, mid+1, end, target);
        }
        if (A[mid] >= A[start]) {
            if (A[mid] <= A[end-1]) {
                if (target > A[mid]) {
                    return binarySearch(A, mid+1, end, target);
                }
                else {
                    return binarySearch(A, start, mid, target);
                }
            }
            else {
                if (target > A[mid] || target <= A[end-1]) {
                    return f(A, mid+1, end, target);
                }
                else {
                    return binarySearch(A, start, mid, target);
                }
            }
        }
        else {
            if (target >= A[start] || target < A[mid]) {
                return f(A, start, mid, target);
            }
            else {
                return binarySearch(A, mid+1, end, target);
            }
        }
    }
    bool binarySearch(int A[], int start, int end, int target) {
        while(start <= end) {
            int mid = (start + end)/2;
            if (target == A[mid]) {
                return true;
            }
            if (target < A[mid]) {
                end = mid-1;
            }
            if (target > A[mid]) {
                start = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    int A[] = {4,4,4,4,6,1,2};
    Solution s;
    cout<<s.search(A, 7, 3);
    return 0;
}
