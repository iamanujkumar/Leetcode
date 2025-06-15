class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string maxS = s;
        for (char c : s) {
            if (c != '9') {
                char from = c;
                for (char& ch : maxS) {
                    if (ch == from) ch = '9';
                }
                break;
            }
        }

        // For min: try replacing the first digit (if not 1) with 1
        string minS = s;
        if (s[0] != '1') {
            char from = s[0];
            for (char& ch : minS) {
                if (ch == from) ch = '1';
            }
        } else {
            // Replace any digit (not 0 or 1) from 2nd onwards with 0
            for (int i = 1; i < s.length(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char from = s[i];
                    for (char& ch : minS) {
                        if (ch == from) ch = '0';
                    }
                    break;
                }
            }
        }
        int maxNum = stoi(maxS);
        int minNum = stoi(minS);
        return maxNum - minNum;
    }
};
