#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) {
            return -1;
        }
        return f(A, 0, n, target);
    }
    int binarySearch(int A[], int start, int end, int target) {
        while(start <= end) {
            int mid = (start + end)/2;
            if (target == A[mid]) {
                return mid;
            }
            if (target < A[mid]) {
                end = mid-1;
            }
            if (target > A[mid]) {
                start = mid + 1;
            }
        }
        return -1;
    }
    int f(int A[], int start, int end, int target) {
        if (A[start] < A[end-1]) {
            return binarySearch(A, start, end, target);
        }
        if (target > A[end-1] && target < A[start]) {
            return -1;
        }
        int mid = (start + end)/2;
        if (target == A[mid]) {
            return mid;
        }
        if (A[mid] > A[start]) {
            if (target > A[mid] || target <= A[end-1]) {
                return f(A, mid+1, end, target);
            }
            else {
                return binarySearch(A, start, mid, target);
            }
        }
        if (A[mid] < A[start]) {
            if (target < A[mid] || target >= A[start]) {
                return f(A, start, mid, target);
            }
            else {
                return binarySearch(A, mid, end, target);
            }
        }
        return -1;
    }
};

int main()
{
    int A[] = {1};
    Solution s;
    cout<<s.search(A, 1, 3);
    return 0;
}
