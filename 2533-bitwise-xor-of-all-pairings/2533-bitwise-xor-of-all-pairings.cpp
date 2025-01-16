class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b = 0;
        for (int num : nums1) {
            a ^= num;
        }
        for (int num : nums2) {
            b ^= num;
        }
        int res = 0;
        if (nums2.size() % 2 != 0) {
            res ^= a;
        }
        if (nums1.size() % 2 != 0) {
            res ^= b;
        }
        return res;
    }
};
