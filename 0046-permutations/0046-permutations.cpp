class Solution {
    private:
    void fun(vector<int>nums,vector<vector<int>>&ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            fun(nums,ans,index+1);
            swap(nums[index],nums[j]);
        }


    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;

        fun(nums,ans,index);
        return ans;
    }
};