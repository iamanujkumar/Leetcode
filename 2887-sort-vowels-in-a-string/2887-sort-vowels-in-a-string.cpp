class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<char> v;
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        int idx = 0;
        for (char &c : s) {
            if (vowels.find(c) != string::npos) {
                c = v[idx++];
            }
        }
        return s;
    }
};
