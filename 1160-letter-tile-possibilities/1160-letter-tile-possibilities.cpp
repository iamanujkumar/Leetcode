class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mp;
        for (char c : tiles) mp[c]++;
        return backtrack(mp);
    }

    int backtrack(unordered_map<char, int>& mp) {
        int final = 0;
        for (auto& [tile, freq] : mp) {
            if (freq > 0) {
                final++;
                mp[tile]--;
                final += backtrack(mp);
                mp[tile]++;
            }
        }
        return final;
    }
};