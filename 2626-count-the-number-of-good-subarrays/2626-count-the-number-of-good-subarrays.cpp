class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long count = 0;
        long long pairs = 0;
        int left = 0;
        for (int st = 0; st < nums.size(); ++st) {
            int val = nums[st];
            pairs += mp[val];
            mp[val]++;
            while (pairs >= k) {
                count += nums.size() - st;
                mp[nums[left]]--;
                pairs -= mp[nums[left]];
                left++;
            }
        }
        return count;
    }
};
