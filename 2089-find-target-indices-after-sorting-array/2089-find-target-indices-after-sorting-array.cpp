class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0, equal=0;
        vector<int>v;
        for(int x:nums){
            if(x<target){
                smaller++;
            }
            else if(x==target){
                equal++;
            }
        }
        for(int i=smaller;i<smaller+equal;i++){
            v.push_back(i);
        }
        return v;
    }
};