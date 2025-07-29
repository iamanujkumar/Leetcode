class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit_last_seen(32, -1); // for bits 0 to 31
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            // Update the bit_last_seen array for nums[i]
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    bit_last_seen[b] = i;
                }
            }

            // Compute the farthest index we must include to get max OR
            int max_len = i;
            for (int b = 0; b < 32; ++b) {
                if (bit_last_seen[b] != -1) {
                    max_len = max(max_len, bit_last_seen[b]);
                }
            }

            ans[i] = max_len - i + 1;
        }

        return ans;
    }
};
