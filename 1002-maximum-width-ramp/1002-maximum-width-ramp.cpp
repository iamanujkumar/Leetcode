class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || (nums[st.top()] > nums[i])){
                st.push(i);
            }
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && (nums[i]>= nums[st.top()])){
                int l=st.top();
                ans=max(ans,i-l);
                st.pop();
            }
            if(st.empty()){
                break;
            }
        }
        return ans;
    }
};