class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int minBuy = prices[0];

        for(auto& sell : prices){
            maxP = max(maxP, sell - minBuy);
            minBuy = min(sell,minBuy);
        }

        return maxP;
    }
};
