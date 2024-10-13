class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi=INT_MIN; 
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> mpq;
        int k=nums.size();
        for(int i=0;i<k;++i){ 
            maxi=max(maxi,nums[i][0]);
            mpq.push({nums[i][0],i,0});
        }

        int min_L=0;  
        int max_R=INT_MAX;
        while(1){     
            auto curr = mpq.top();
            mpq.pop();

            int r=curr[1];
            int c=curr[2];
            int currVal=curr[0];
            
            if(max_R-min_L > maxi-currVal){
                min_L=currVal;
                max_R=maxi;
            }
            if(c<nums[r].size()-1){
                mpq.push({nums[r][c+1],r,c+1});
                maxi = max(maxi,nums[r][c+1]);
            } else
                break;
        }
        return {min_L,max_R};
    }
};