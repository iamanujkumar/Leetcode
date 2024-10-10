class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int l=0,r=0,n=s.size();
        int hash[256];
        fill(hash, hash + 256, -1);
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            ans=max(ans,len);
            hash[s[r]]=r;
            r++;
        }
        return ans;
    }
};