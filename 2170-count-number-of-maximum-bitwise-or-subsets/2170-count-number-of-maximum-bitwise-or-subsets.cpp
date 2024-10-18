class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        int count = 0;
        function<void(int, int)> backtrack = [&](int oa, int crot) {
            if (oa == nums.size()) {
                if (crot == maxOr) {
                    count++;
                }
                return;
            }
            backtrack(oa + 1, crot | nums[oa]);
            backtrack(oa + 1, crot);
        };
        backtrack(0, 0);
        return count;
    }
};
