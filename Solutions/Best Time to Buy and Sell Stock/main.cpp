class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int min = prices[0];
        int max = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
                max = max > 0? max:0;
            }
            else {
                int tmp = prices[i] - min;
                max = tmp > max ? tmp: max;
            }
        }
        return max;
    }
};