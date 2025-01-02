class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        string vowels = "aeiou";
        vector<int> prefix(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            if (vowels.find(words[i][0]) != string::npos && vowels.find(words[i].back()) != string::npos) {
                prefix[i] = 1;
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            prefix[i] += prefix[i - 1];
        }
        vector<int> vec;
        for (auto& query : queries) {
            int li = query[0], ri = query[1];
            if (li > 0) {
                vec.push_back(prefix[ri] - prefix[li - 1]);
            } else {
                vec.push_back(prefix[ri]);
            }
        }
        return vec;
    }
};
