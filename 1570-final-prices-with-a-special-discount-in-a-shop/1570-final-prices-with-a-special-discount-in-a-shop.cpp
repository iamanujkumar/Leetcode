class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(prices);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && prices[s.top()] >= prices[i]) {
                int idx = s.top();
                s.pop();
                ans[idx] = prices[idx] - prices[i];
            }
            s.push(i);
        }
        return ans;
    }
};
