class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (k <= 0) {
            return ;
        }
        k = k % n;
        rotate_elem(nums, n-k);
        rotate_elem(nums + n-k, k);
        rotate_elem(nums,n);
    }
    void rotate_elem(int nums[], int n) {
        int begin = 0, end = n - 1;
        while(begin < end) {
            int tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }
};