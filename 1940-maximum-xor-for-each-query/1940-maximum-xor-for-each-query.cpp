#include <vector>

class Solution {
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxi = (1 << maximumBit) - 1;
        std::vector<int> vec(n);
        int txor = 0;
        for (int num : nums) {
            txor ^= num;
        }
        for (int i = 0; i < n; ++i) {
            vec[i] = txor ^ maxi;
            txor ^= nums[n - 1 - i];
        }
        return vec;
    }
};
