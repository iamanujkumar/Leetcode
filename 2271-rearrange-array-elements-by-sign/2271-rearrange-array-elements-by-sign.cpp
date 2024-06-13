class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg, ans;

        for (int num : nums) {
            if (num>0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }
        
        for(int i=0;i<pos.size();i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        
        return ans;
    }
};
