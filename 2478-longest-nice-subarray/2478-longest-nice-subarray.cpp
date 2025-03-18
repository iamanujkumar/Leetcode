class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, currentOR = 0, maxLength = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while ((currentOR & nums[right]) != 0) {
                currentOR ^= nums[left];
                left++;              
            }
            currentOR |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};