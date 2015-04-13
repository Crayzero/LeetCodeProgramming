class Solution:
    # @return an integer as the maximum profit
    def maxProfit(self, k, prices):
        k_array = []
        flag = False
        if k <= 0:
            return 0
        for i in range(len(prices)-1):
            if not flag and prices[i] < prices[i+1]:
                k_array.append(prices[i])
                flag = True
            elif flag and prices[i] > prices[i+1]:
                k_array.append(prices[i])
                flag = False
        else:
            if flag:
                k_array.append(prices[i+1])
        return self.get_k_profit(k_array, k)

    def get_k_profit(self, array, k):
        if k >= len(array)/2:
            return self.get_profit(array)
        else:
            min = -1
            index_min = 0
            for i in range(len(array)-1):
                t_min = 0
                if i % 2 == 0:
                    t_min = array[i+1] - array[i]
                else:
                    t_min = array[i] - array[i+1]
                if min < 0 or t_min < min:
                    min = t_min
                    index_min = i
            array = [array[i] for i in range(len(array)) if i != index_min and i != index_min+1]
            return self.get_k_profit(array, k)

    def get_profit(self, array):
        return sum([array[i+1] - array[i] for i in range(len(array)) if i % 2 == 0])