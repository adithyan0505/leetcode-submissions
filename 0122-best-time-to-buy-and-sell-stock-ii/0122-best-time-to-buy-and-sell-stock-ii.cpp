class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buying = prices[0], profit = 0, size = prices.size();
        for(int i = 1;i < size;i++){
            if(buying > prices[i])
                buying = prices[i];
            else{
                profit += prices[i] - buying;
                buying = prices[i];
            }
        }
        return profit;
    }
};