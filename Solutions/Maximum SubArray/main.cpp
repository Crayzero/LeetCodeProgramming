#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        return f(A, 0, n-1);
    }
    int f(int A[], int left, int right) {
        if (left == right) {
            return A[left];
        }
        int center = (left + right)/2;
        int max_left_sum = f(A, left, center);
        int max_right_sum = f(A, center+1, right);

        int max_left_border_sum = A[center], max_right_border_sum = A[center+1];
        int left_tmp = max_left_border_sum, right_tmp = max_right_border_sum;
        for(int i = center-1; i >= left; i--) {
            left_tmp += A[i];
            max_left_border_sum = max(max_left_border_sum, left_tmp);
        }
        for(int i = center+2; i <= right; i++) {
            right_tmp += A[i];
            max_right_border_sum = max(right_tmp, max_right_border_sum);
        }
        return max(max_left_border_sum+max_right_border_sum, max(max_left_sum,max_right_sum));
    }
};

int main()
{
    int A[] = {1,2,3};
    Solution s;
    cout<<s.maxSubArray(A, sizeof(A)/sizeof(*A));
    return 0;
}
