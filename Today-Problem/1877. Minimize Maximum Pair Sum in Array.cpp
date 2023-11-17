class Solution {
public:
   int minPairSum(std::vector<int>& nums) {
    
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    int maxi = 0;

    for (int i = 0; i < n / 2; ++i) {
        maxi = max(maxi, nums[i] + nums[n - 1 - i]);
    }

    return maxi;
}
};