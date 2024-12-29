class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = words.size();
        int n = words[0].size();
        int temp = target.size();
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }
        vector<long long> dp(temp + 1, 0);
        dp[0] = 1;
        for (int col = 0; col < n; ++col) {
            for (int j = temp - 1; j >= 0; --j) {
                char c = target[j];
                dp[j + 1] = (dp[j + 1] + dp[j] * freq[c - 'a'][col]) % MOD;
            }
        }
        return dp[temp];
    }
};
