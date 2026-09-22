class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<2*n;i++){
            int curr = nums[i%n];
            while(!st.empty() && nums[st.top()]<curr){
                ans[st.top()] = curr;
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
        }
        return ans;
    }
};