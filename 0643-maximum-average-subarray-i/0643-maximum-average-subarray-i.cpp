class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        double maxi=-1e9;
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            if(j-i+1==k){
                maxi = max(maxi, (double)sum/k);
                sum-=nums[i];
                i++;
            }
        }
        return maxi;
    }
};