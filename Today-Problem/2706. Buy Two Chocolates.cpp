class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        for(int i=0;i<prices.size()-1;i++){
            int sum=0;
            for(int j=i+1;j<prices.size();j++){

                sum=prices[i]+prices[j];
                if(sum>money) return money;
                else return money-sum;
            }
            
        }
        return money;

    }
};