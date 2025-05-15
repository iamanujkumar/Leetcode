class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int n = words.size();
        if (n == 0) return result;

        result.push_back(words[0]);
        int lastGroup = groups[0];

        for (int i = 1; i < n; ++i) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }
        return result;
    }
};
