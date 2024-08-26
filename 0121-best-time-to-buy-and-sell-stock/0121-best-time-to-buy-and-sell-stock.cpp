class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], profit = 0, size = prices.size(),curr_profit;
        for(int i = 0;i < size;i++){
            if(min > prices[i])
                min = prices[i];
            else{
                int curr_profit = prices[i] - min;
                if(curr_profit > profit)
                    profit = curr_profit;
            }
        }
        return profit;
    }
};