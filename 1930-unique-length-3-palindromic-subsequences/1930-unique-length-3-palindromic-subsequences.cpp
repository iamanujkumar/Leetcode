class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        int count = 0;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c]) continue;
            int l = first[c], r = last[c];
            vector<bool> seen(26, false);
            for (int i = l + 1; i < r; i++) {
                seen[s[i] - 'a'] = true;
            }
            count += std::count(seen.begin(), seen.end(), true);
        }
        return count;
    }
};
