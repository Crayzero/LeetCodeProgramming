#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> all_set;
        for(auto beg = num.begin(); beg != num.end(); beg++) {
            all_set.insert(*beg);
        }

        int count_max = 0;
        while(all_set.size()) {
            int count = 1;
            auto elem_iter = all_set.begin();
            int elem = *elem_iter;
            cout<<elem<<" ";
            while(all_set.find(++elem) != all_set.end()) {
                count++;
                cout<<elem<<" ";
                all_set.erase(elem);
            }
            elem = *elem_iter;
            while(all_set.find(--elem) != all_set.end()) {
                count++;
                cout<<elem<<" ";
                all_set.erase(elem);
            }
            all_set.erase(elem_iter);
            if (count > count_max) {
                count_max = count;
            }
            cout<<endl;
        }
        return count_max;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {};
    cout<<s.longestConsecutive(nums);
    return 0;
}
