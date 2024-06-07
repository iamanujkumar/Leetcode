class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
             maxprofit = max(maxprofit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxprofit;
    }
};