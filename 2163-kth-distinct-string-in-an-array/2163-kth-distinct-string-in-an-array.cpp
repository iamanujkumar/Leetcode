class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string s="";
        int count=0;
        vector<string>v;
        unordered_map<string,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:arr){
            if(mp[it]==1){
                v.push_back(it);
            }
        }
        if(v.size()>=k){
            s=v[k-1];
        }
         return s;
    }
};