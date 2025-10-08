class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        int max_portion = potions[potions.size()-1];
        for(int i=0;i<spells.size();i++){
            int spell = spells[i];
            long long min_portion = ceil((1.0*success)/spell);
            if(min_portion>max_portion){
                ans.push_back(0);
                continue;
            }
            int index = lower_bound(begin(potions),end(potions),min_portion)-begin(potions);
            int count = potions.size()-index;
            ans.push_back(count);
        }
        return ans;
    }
};