class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0) return 0;
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] < k) {
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);
                return max(left, right);
            }
        }
        return s.size();
    }
};
