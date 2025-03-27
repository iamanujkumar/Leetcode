class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0], count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        int tcl = 0;
        for (int num : nums) {
            if (num == candidate) tcl++;
        }
        int lfc = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) lfc++;
            int rightCount = tcl - lfc;
            if (lfc * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }
        return -1;
    }
};
