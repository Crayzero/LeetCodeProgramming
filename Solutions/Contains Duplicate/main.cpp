#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            if (set.find(*iter) == set.end())
                set.insert(*iter);
            else
                return true;
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i <= k && i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = i;
            else
                return true;
        }
        for(int i = k+1; i < nums.size(); i++) {
            m.erase(nums[i-k-1]);
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = i;
            else
                return true;
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> m;
        int left = 0;
        int right = 0;
        for (; right < nums.size(); right++) {
            if (right - left > k && m.find(nums[left]) != m.end())
                m.erase(nums[left++]);
            auto low = m.lower_bound(nums[right] - t);
            if (low != m.end() && abs(low->first - nums[right]) <= t)
                return true;
            m[nums[right]] = right;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,1,2,3,4,5,3};
    //cout<<s.containsDuplicate(nums);
    cout<<s.containsNearbyDuplicate(nums, 2);
    return 0;
}
