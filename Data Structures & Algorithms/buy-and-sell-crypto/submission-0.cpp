class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1;
        int ans=0;

        while(r<prices.size()){
            if(prices[r]>prices[l]){
                int temp = prices[r]-prices[l];
                ans = max(ans, temp);
            }
            else{
                l=r;
            }
            r++;
        }

        return ans;
    }
};
