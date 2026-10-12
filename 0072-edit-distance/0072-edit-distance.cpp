class Solution {
public:
    int fun(int i, int j, string word1, string word2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]) return fun(i-1, j-1, word1, word2,dp);

        int insertOp = fun(i, j-1, word1, word2,dp);
        int deleteOp = fun(i-1, j, word1, word2,dp);
        int replaceOp = fun(i-1, j-1, word1, word2,dp);

        return dp[i][j] = 1+ min(insertOp, min(deleteOp, replaceOp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        return fun(word1.size()-1, word2.size()-1, word1, word2,dp);
    }
};