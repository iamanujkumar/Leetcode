class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int inc_len = 1, dec_len = 1, ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc_len++;
                dec_len = 1; 
            } else if (nums[i] < nums[i - 1]) {
                dec_len++; 
                inc_len = 1;
            } else {
                inc_len = 1;
                dec_len = 1;
            }
            ans = max(ans, max(inc_len, dec_len));
        }  
        return ans;
    }
};
