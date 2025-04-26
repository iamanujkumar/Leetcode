class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastMin = -1, lastMax = -1, lst = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                lst = i;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            int validStart = min(lastMin, lastMax);
            if (validStart > lst) {
                ans += (validStart - lst);
            }
        }
        return ans;
    }
};
