class Solution {
public:
    int binary_search(int l,int r,vector<int>&nums,int sum){
        int k = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]<sum){
                k = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return k;
    }
    int triangleNumber(vector<int>& nums) {
        int count=0;
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<nums.size()-1;j++){
                int sum=nums[i]+nums[j];
                int k = binary_search(j+1,nums.size()-1,nums,sum);
                if(k!=-1) count+=(k-j);
            }
        }
        return count;
    }
};