class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int sum = 0;
        vector<int> buy;
        vector<int> sell;
        bool buy_flag = true;
        for(int i = 0; i < static_cast<int>(prices.size()); i++) {
            if(prices[i+1] >= prices[i] && buy_flag) {
                buy.push_back(prices[i]);
                buy_flag = false;
            }
            else if (prices[i+1] <= prices[i] && !buy_flag) {
                sell.push_back(prices[i]);
                buy_flag = true;
            }
        }
        if (!buy_flag) {
            sell.push_back(prices[prices.size()-1]);
        }
        for(int i = 0; i < static_cast<int>(buy.size()); i++) {
            sum += sell[i] - buy[i];
        }
        return sum;
    }
};