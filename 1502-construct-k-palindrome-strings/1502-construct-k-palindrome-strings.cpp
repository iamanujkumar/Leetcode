class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;
        vector<int> vec(26, 0);
        for (char c : s) {
            vec[c - 'a']++;
        }
        int cnt = 0;
        for (int count : vec) {
            if (count % 2 != 0) cnt++;
        }
        return cnt <= k;
    }
};
