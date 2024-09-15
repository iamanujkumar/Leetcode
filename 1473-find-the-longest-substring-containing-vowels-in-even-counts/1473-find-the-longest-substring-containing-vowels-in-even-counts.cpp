class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> idx;
        idx[0] = -1;  
        
        int val = 0;
        int max_len = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') {
                val ^= 1 << 0;
            } else if (s[i] == 'e') {
                val ^= 1 << 1;
            } else if (s[i] == 'i') {
                val ^= 1 << 2;
            } else if (s[i] == 'o') {
                val ^= 1 << 3;
            } else if (s[i] == 'u') {
                val ^= 1 << 4;
            }
            
            if (idx.find(val) != idx.end()) {
                max_len = max(max_len, i - idx[val]);
            } else {
                idx[val] = i;
            }
        }
        
        return max_len;
    }
};
