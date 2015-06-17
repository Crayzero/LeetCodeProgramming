class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int begin = 0;
        int end;
        int sum = 0;
        int res = INT_MAX;
        for(end = begin; end < nums.size(); end++) {
            sum += nums[end];
            for(; begin <= end && sum >= s; begin++) {
                res = min(res, end - begin+1);
                sum -= nums[begin];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};