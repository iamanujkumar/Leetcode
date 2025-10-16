class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            int mod = (x % value + value) % value;
            mp[mod]++;
        }
        int mex = 0;
        while (true) {
            int mod = mex % value;
            if (mp[mod] > 0) {
                mp[mod]--;
                mex++;
            } else {
                break;
            }
        }
        return mex;
    }
};
