class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string str = s1 + " " + s2;
        unordered_map<string, int> mp;
        stringstream ss(str);
        string word;
        while (ss >> word) {
            mp[word]++;
        }
        vector<string> ans;
        for (const auto& entry : mp) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};
