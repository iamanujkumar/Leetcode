class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        while (true) {
            unordered_set<int> seen;
            bool hasDuplicate = false;
            for (int num : nums) {
                if (seen.count(num)) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(num);
            }
            if (!hasDuplicate) break;
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            operations++;
        }
        return operations;
    }
};
