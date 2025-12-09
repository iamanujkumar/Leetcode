class Solution {
public:
    int M = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int ans = 0;
        for(int &num : nums) {
            mp2[num]++;
        }
        for(int &num : nums) {
            mp2[num]--;
            int left  = mp1[num*2];
            int right = mp2[num*2];
            ans = (ans + (1LL * left * right)) % M;
            mp1[num]++;
        }
        return ans;
    }
};