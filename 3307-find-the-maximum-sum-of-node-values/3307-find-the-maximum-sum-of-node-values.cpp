class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0;
        int minLoss = INT_MAX;
        int countPositive = 0;
        for (int num : nums) {
            int gain = (num ^ k) - num;
            if (gain > 0) {
                countPositive++;
                total += num ^ k;
            } else {
                total += num;
            }
            minLoss = min(minLoss, abs(gain));
        }
        if (countPositive % 2 == 1) {
            total -= minLoss;
        }
        return total;
    }
};
