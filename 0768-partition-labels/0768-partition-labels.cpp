class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        int maxi = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            maxi = max(maxi, lastIndex[s[i] - 'a']);
            if (i == maxi) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};