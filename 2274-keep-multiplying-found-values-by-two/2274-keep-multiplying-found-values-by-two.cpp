class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(st.find(original)!=st.end()){
                original=original*2;
            }
            else break;
        }
        return original;
    }
};