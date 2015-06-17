#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return f(nums, k, 0, nums.size());
    }
    int f(vector<int> &nums, int k, int begin, int end) {
        cout<<begin<<" "<<end<<" "<<k<<" "<<nums[begin]<<endl;
        for(int i = begin; i < end; i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        if (begin == end - 1)
            return nums[begin];
        int e = nums[begin];
        int left = begin+1, right = end-1;
        while(left <= right) {
            for(;nums[left] > e && left < end; left++);
            for(;nums[right] < e && right >= begin; right--);
            if (left <= right)
                swap(nums[left++], nums[right--]);
        }
        swap(nums[begin], nums[right]);
        for(int i = begin; i < end; i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        if (left - begin == k)
            return nums[left-1];
        if (left - begin < k)
            return f(nums, k - left + begin, left, end);
        else
            return f(nums, k, begin, left-1);
    }
};

int main()
{
    vector<int> nums = {99,99};
    Solution s;
    cout<<s.findKthLargest(nums, 1);
    return 0;
}
