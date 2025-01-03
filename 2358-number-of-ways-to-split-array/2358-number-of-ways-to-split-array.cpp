class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        long long leftSum = 0;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            long long rightSum = sum - leftSum;
            if (leftSum >= rightSum) {
                count++;
            }
        }
        return count;
    }
};
