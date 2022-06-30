class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # index of variables
        low = 0
        high = 0
        profit = 0
        
        i = 1
        while i < len(prices):
            if prices[low] > prices[i]:
                low = i
            elif prices[i] - prices[low] > profit:
                high = i
                profit = prices[i] - prices[low]
            i += 1
        return profit