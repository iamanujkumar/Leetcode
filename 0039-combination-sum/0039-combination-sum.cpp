class Solution {
public:
    void findCombination(vector<int>arr, int ind, int k,vector<int>v, vector<vector<int>>&ans){
        if(ind==arr.size()){
            if(k==0){
                ans.push_back(v);
            }
            return;
        }
        if(arr[ind]<=k){
            v.push_back(arr[ind]);
            findCombination(arr,ind,k-arr[ind],v,ans);
            v.pop_back();
        }
        findCombination(arr,ind+1,k,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        findCombination(candidates,0, target, v,ans);
        return ans;
    }
};