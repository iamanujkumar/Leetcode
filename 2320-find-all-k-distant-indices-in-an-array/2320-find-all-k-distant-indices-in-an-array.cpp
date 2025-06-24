class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> isValid(n, false);
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    isValid[i] = true;
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (isValid[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
