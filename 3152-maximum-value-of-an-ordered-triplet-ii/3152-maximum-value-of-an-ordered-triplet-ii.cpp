class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        long long cnt = 0;
        int prmax = nums[0];
        vector<int> maxSuffix(n, 0);
        maxSuffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxSuffix[i] = max(maxSuffix[i + 1], nums[i]);
        }
        for (int j = 1; j < n - 1; j++) {
            if (prmax > nums[j]) {
                cnt = max(cnt, (long long)(prmax - nums[j]) * maxSuffix[j + 1]);
            }
            prmax = max(prmax, nums[j]);
        }
        return cnt;
    }
};
