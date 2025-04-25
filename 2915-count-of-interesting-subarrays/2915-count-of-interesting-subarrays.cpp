class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0;
        unordered_map<int, long long> mp;
        int current = 0;
        mp[0] = 1;
        for (int num : nums) {
            if (num % modulo == k) {
                current = (current + 1) % modulo;
            }
            int target = (current - k + modulo) % modulo;
            count += mp[target];
            mp[current]++;
        }
        return count;
    }
};
