class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3, 0);
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            v[s[right] - 'a']++;
            while (v[0] > 0 && v[1] > 0 && v[2] > 0) {
                ans += s.size() - right;
                v[s[left] - 'a']--; 
                left++;
            }
        }
        return ans;
    }
};
