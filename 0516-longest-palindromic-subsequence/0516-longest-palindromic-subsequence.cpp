class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string str2=s;
        reverse(str2.begin(),str2.end());
         int n=s.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ls=dp[n][m];
        return ls;     
    }
};