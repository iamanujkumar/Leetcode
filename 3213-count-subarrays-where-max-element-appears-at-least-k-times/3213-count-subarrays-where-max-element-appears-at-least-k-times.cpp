class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        long long res = 0;
        int left = 0, count = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxi) count++;
            while (count >= k) {
                res += (n - right);
                if (nums[left] == maxi) count--;
                left++;
            }
        }
        return res;
    }
};
