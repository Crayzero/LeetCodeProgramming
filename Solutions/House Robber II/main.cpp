#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int *dp1_1 = new int[nums.size()];
        int *dp1_2 = new int[nums.size()];
        int *dp2_1 = new int[nums.size()];
        int *dp2_2 = new int[nums.size()];
        int max_1, max_2;
        for(size_t i = 0; i < nums.size(); i++) {
            int last_one = i >= 2 ? dp1_1[i-2] : 0;
            int last_two = i >= 1 ? dp1_2[i-1] : 0;
            if (i != nums.size())
                dp1_1[i] = max(last_one, last_two) + nums[i];
            last_one = i >= 1 ? dp1_1[i-1] : 0;
            last_two = i >= 1 ? dp1_2[i-1] : 0;
            dp1_2[i] = max(last_one, last_two);
        }
        max_1 = dp1_2[nums.size()-1];

        dp2_1[0] = dp2_2[0] = 0;
        for(size_t i = 1; i < nums.size(); i++) {
            int last_two = i >= 2 ? dp2_1[i-2] : 0;
            dp2_1[i] = max(last_two, dp2_2[i-1]) + nums[i];
            dp2_2[i] = max(dp2_1[i-1], dp2_2[i-1]);
        }
        max_2 = max(dp2_1[nums.size()-1], dp2_2[nums.size()-1]);
        return max(max_1, max_2);
    }
};

int main()
{
    vector<int> nums = {1};
    Solution s;
    cout<<s.rob(nums);
    return 0;
}
