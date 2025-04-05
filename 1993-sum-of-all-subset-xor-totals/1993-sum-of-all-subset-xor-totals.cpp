class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int all = 0;
        for (int num : nums) {
            all |= num;
        }
        int n = nums.size();
        return all * (1 << (n - 1));
    }
};
