class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long>st2;
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long frt=target-sum;
                    if(st2.find(frt) != st2.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],int(frt)};
                        sort(temp.begin(),temp.end());
                         st.insert(temp);
                    }
                   st2.insert(nums[k]);
                }
                
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};