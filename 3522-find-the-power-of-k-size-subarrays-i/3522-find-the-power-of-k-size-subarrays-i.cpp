class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            bool flag = true;
            int maxi = nums[i];
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    flag = false;
                    break;
                }
                maxi = max(maxi, nums[j + 1]);
            }

            if (flag) {
                ans.push_back(maxi);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};