class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp(nums.begin(), nums.end());
        int required_unique = mp.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> st;
            for (int j = i; j < n; ++j) {
                st.insert(nums[j]);
                if (st.size() == required_unique) {
                    count++;
                }
            }
        }
        return count;
    }
};
