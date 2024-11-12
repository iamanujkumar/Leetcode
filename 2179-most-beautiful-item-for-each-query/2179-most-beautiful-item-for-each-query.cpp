#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Sort items based on price
        sort(items.begin(), items.end());

        // Step 2: Precompute maximum beauty up to each price
        vector<int> maxBeautyAtPrice;
        vector<int> prices;
        int maxBeautySoFar = 0;
        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            maxBeautySoFar = max(maxBeautySoFar, beauty);
            // Maintain only unique prices with the max beauty up to that price
            if (prices.empty() || prices.back() != price) {
                prices.push_back(price);
                maxBeautyAtPrice.push_back(maxBeautySoFar);
            } else {
                maxBeautyAtPrice.back() = maxBeautySoFar;  // Update max beauty for the same price
            }
        }

        // Step 3: Process each query using binary search
        vector<int> answer;
        for (int q : queries) {
            auto it = upper_bound(prices.begin(), prices.end(), q);
            if (it == prices.begin()) {
                answer.push_back(0); // No price <= query
            } else {
                --it; 
                int index = it - prices.begin();
                answer.push_back(maxBeautyAtPrice[index]);
            }
        }
        return answer;
    }
};
