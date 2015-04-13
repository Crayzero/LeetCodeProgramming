#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int size = gas.size();
        vector<int > rest(size,0);
        if (gas.size() == 0) {
            return -1;
        }
        for(int i = 0; i < size; i++) {
            rest[i] = gas[i] - cost[i];
        }
        int max,max_index;
        max = rest[size-1];
        max_index = size-1;
        int tmp = max;
        for(int i = size-2; i>=0; i--) {
            tmp += rest[i];
            if (max < tmp) {
                max = tmp;
                max_index = i;
            }
        }
        if (tmp < 0) {
            return -1;
        }
        return max_index;
    }
};

int main()
{
    vector<int> gas = {2};
    vector<int> cost = {3};
    Solution s;
    cout<<s.canCompleteCircuit(gas,cost)<<endl;
    return 0;
}
