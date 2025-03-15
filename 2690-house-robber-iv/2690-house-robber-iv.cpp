class Solution {
public:
    bool canRob(vector<int>& nums, int k, int mid) {
        int val = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                val++;
                i++;
            }
        }
        return val >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int st = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());
        int ans = end;
        while (st <= end) {
            int mid = st + (end - st) / 2;         
            if (canRob(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1; 
            }
        }
        return ans;
    }
};
