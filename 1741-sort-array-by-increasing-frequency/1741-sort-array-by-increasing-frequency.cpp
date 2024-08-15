class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>,decltype(cmp)> mpq;
        for(auto it : mp){
            mpq.push({it.second, it.first});
        }

        vector<int> v;
        while(!mpq.empty()){
            int freq = mpq.top().first;
            int num = mpq.top().second;
            for(int i = 0; i < freq; i++) {
                v.push_back(num);
            }
            mpq.pop();
        }
        return v;
    }
};
