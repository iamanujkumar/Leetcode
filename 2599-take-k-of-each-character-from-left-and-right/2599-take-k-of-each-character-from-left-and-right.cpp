class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
            return -1;
        }
        int n = s.length();
        unordered_map<char, int> mp2 = {{'a', 0}, {'b', 0}, {'c', 0}};
        int lft = 0, maxi = 0;
        for (int right = 0; right < n; ++right) {
            mp2[s[right]]++;
            while (mp2['a'] > mp['a'] - k ||
                   mp2['b'] > mp['b'] - k ||
                   mp2['c'] > mp['c'] - k) {
                mp2[s[lft]]--;
                lft++;
            }
            maxi = max(maxi, right - lft + 1);
        }
        return n - maxi;
    }
};
