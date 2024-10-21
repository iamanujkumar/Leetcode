class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstrings;
        return backtrack(s, 0, uniqueSubstrings);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& uniqueSubstrings) {
        if (start == s.size()) return 0;
        int maxSplits = 0;
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (uniqueSubstrings.find(substring) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(substring);
                int currentSplits = 1 + backtrack(s, end, uniqueSubstrings);
                maxSplits = max(maxSplits, currentSplits);
                uniqueSubstrings.erase(substring);
            }
        }
        
        return maxSplits;
    }
};
