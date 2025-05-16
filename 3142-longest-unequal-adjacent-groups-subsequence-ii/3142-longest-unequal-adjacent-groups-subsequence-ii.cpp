class Solution {
    int hammingDistance(const string &a, const string &b) {
        int hamming_distance = 0;
        for (int i = 0, n = a.size(); i < n; ++i)
            if (a[i] != b[i])
                ++hamming_distance;
        return hamming_distance;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> lis(n, 1), parent(n, -1);

        int lis_len = 1, lis_end = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j]
                    && words[i].size() == words[j].size()
                    && hammingDistance(words[i], words[j]) == 1
                    && lis[i] + 1 > lis[j])
                {
                    lis[j] = lis[i] + 1;
                    parent[j] = i;
                    if (lis[j] > lis_len) {
                        lis_len = lis[j];
                        lis_end = j;
                    }
                }
            }
        }
        vector<string> ans;
        for (int cur = lis_end; cur != -1; cur = parent[cur])
            ans.push_back(words[cur]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};