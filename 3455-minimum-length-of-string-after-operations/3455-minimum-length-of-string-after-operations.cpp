class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int count=0;
        for(auto it:mp){
            if(it.second>=3 && it.second%2==0){
                count+=2;
            }
            else if(it.second>=3 && it.second%2!=0){
                count+=1;
            }
            else count+=it.second;
        }
        return count;
    }
};