class Solution {
public:
    int minimumSize(vector<int>& nums, int maxsa) {
        // Binary search bounds
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;
        
        // Binary search
        while (left <= right) {
            int mid = left + (right - left) / 2; // Candidate pen
            if (isFeasible(nums, maxsa, mid)) {
                result = mid; // Update result with feasible pen
                right = mid - 1; // Try for a smaller pen
            } else {
                left = mid + 1; // Try for a larger pen
            }
        }
        return result;
    }
    
private:
    // Helper to check if a given pen is feasible
    bool isFeasible(const vector<int>& nums, int maxsa, int pen) {
        int sa = 0;
        for (int balls : nums) {
            if (balls > pen) {
                sa += (balls - 1) / pen;
            }
        }
        return sa <= maxsa;
    }
};
