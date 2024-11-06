class Solution {
public:
    bool canSortArray(vector<int>& nums) {
         int n=nums.size();

        int prev_segment_max=INT_MIN;
        int curr_segment_max = nums[0];
        int curr_segment_min = nums[0];
        int dyy = __builtin_popcount(nums[0]);
        int i=1;
        while(i<n){
            
            //Extract current segment
            while(i<n and __builtin_popcount(nums[i])==dyy){
                curr_segment_max = max(curr_segment_max,nums[i]);
                curr_segment_min = min(curr_segment_min,nums[i]);
                i++;
            }
            if(prev_segment_max > curr_segment_min){
                return false;
            }else if(i<n){
                prev_segment_max = curr_segment_max;
                curr_segment_max = nums[i];
                curr_segment_min = nums[i];
                dyy = __builtin_popcount(nums[i]);
            }
        }
        return true;
    
    }
};