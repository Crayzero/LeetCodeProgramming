#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) {
            return 0;
        }
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        for(int i = 0; i < num.size(); i++) {
            for(int j = i+1; j < num.size()-1; j++) {
                int a = num[i], b = num[j];
                int sum = a + b;
                num.erase(num.begin() + j);
                num.erase(num.begin() + i);
                sum = find_closet(num, target, sum);
                cout<<a<<" "<<b<<" "<<sum<<endl;
                if (abs(target - sum) < abs(target - res)) {
                    res = sum;
                }
                num.insert(num.begin() + i, a);
                num.insert(num.begin() + j, b);
            }
        }
        return res;
    }
    int find_closet(vector<int> &num, int target, int sum) {
        int t = target - sum;
        int left = 0;
        int right = num.size()-1;
        while(left < right-1) {
            int mid = (left + right) / 2;
            if (num[mid] == t) return target;
            if (t < num[mid]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return abs(t-num[left]) < abs(t-num[right]) ? sum + num[left] :sum + num[right];
    }
    int threeSumClosest2(vector<int> &num, int target) {
        if (num.size() < 3) {
            return 0;
        }
        int min = abs(num[0] + num[1] + num[2] - target);
        int res = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); i++) {
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k) {
                int sum = num[i] + num[j] + num[k];
                cout<<num[i]<<" "<<num[j]<<" "<<num[k]<<endl;
                int diff = abs(target - sum);
                if (diff == 0)  return target;
                if (diff < min) {
                    min = diff;
                    res = sum;
                }
                if (sum <= target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> num = {0,0,0};
    cout<<s.threeSumClosest2(num, 1);
    return 0;
}
