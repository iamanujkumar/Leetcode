class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
         int n=nums.size();
        vector<int> res(n);
        int left=0,right=n-1;
        int ls=0,rs=n-1;
        while(left<n){
            if(nums[left]<pivot)    res[ls++]=nums[left];
            if(nums[right]>pivot)   res[rs--]=nums[right];
            left++;
            right--;
        }
        while(ls<=rs)
            res[ls++]=pivot;
        return res;
    }
};