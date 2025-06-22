class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;

        // Iterate over the string in steps of k
        for (int i = 0; i < s.length(); i += k) {
            string group = s.substr(i, k);

            // If the group has fewer than k characters, append fill characters
            if (group.length() < k) {
                group.append(k - group.length(), fill);
            }

            result.push_back(group);
        }

        return result;
    }
};
