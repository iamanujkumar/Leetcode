class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mpq;
        for(auto it:mp){
            mpq.push({it.second,it.first});
            if(mpq.size()>k) mpq.pop();
        }
        while(!mpq.empty()){
            v.push_back(mpq.top().second);
            mpq.pop();
        }


        return v;
    }
};