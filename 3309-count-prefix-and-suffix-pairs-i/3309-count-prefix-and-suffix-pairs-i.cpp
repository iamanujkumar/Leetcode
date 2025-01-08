class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        auto isPreAndSuff = [](const string& st1, const string& st2) {
            int len1 = st1.size();
            int len2 = st2.size();
            if (len1 > len2) return false;
            if (st2.substr(0, len1) != st1) return false;
            if (st2.substr(len2 - len1) != st1) return false;
            return true;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPreAndSuff(words[i], words[j])) {
                    ++count;
                }
            }
        }
        return count;
    }
};
