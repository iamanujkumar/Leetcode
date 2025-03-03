class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>l;
        vector<int>r;
        vector<int>b;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                l.push_back(nums[i]);
            }
            else if (nums[i]>pivot){
                r.push_back(nums[i]);
            }
            else if (nums[i]==pivot){
                b.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<l.size();i++){
            ans.push_back(l[i]);
        }
        for(int i=0;i<b.size();i++){
            ans.push_back(b[i]);
        }
        for(int i=0;i<r.size();i++){
            ans.push_back(r[i]);
        }
        return ans;
    }
};