class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int count=0;
        set<int>st;
        for(auto it: mp){
            st.insert(it.second);
            count++;
        }
        if(st.size()==count) return true;
        return false;

    }
};