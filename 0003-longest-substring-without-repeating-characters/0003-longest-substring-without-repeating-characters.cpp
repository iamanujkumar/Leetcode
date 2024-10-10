class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int hash[256]={0};
            for(int j=i;j<s.size();j++){
                if(hash[s[j]]==1)break;
                int len=j-i+1;
                ans=max(ans,len);
                hash[s[j]]=1;
            }
        }
        return ans;
    }
};