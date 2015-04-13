class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (size <= 1) {
            return 0;
        }
        int *l = new int[size];
        int *r = new int[size];
        int p_min = prices[0];
        l[0] = 0;
        for(int i = 1; i< size; i++) {
            l[i] = max(prices[i] - p_min, l[i-1]);
            p_min = min(prices[i], p_min);
        }
        int p_max = prices[size-1];
        r[size-1] = 0;
        for(int i = size-2; i >=0; i--) {
            r[i] = max(p_max - prices[i], r[i+1]);
            p_max = max(prices[i], p_max);
        }
        int max_profit = 0;
        for(int i = 0; i < size; i++) {
            max_profit = max(max_profit, l[i]+r[i]);
        }
        return max_profit;
    }
};