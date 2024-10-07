class Solution {
public:
    string longestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxLength = 0;
        int endIdx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > maxLength) {
                        int revPos = n - j;
                        if (revPos + dp[i][j] - 1 == i - 1) {
                            maxLength = dp[i][j];
                            endIdx = i - 1;
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        string longestPalindromicSubstring = s.substr(endIdx - maxLength + 1, maxLength);
        
        return longestPalindromicSubstring;
    }
};
