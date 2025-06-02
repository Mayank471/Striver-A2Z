class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0 , minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++) {
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }
            if(prices[i]-minPrice > maxprofit) {
                maxprofit = prices[i]-minPrice;
            }
        }
        return maxprofit;
    }
};