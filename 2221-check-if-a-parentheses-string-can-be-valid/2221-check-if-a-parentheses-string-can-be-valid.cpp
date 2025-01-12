class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;
        int cnt = 0, fcnt = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                ++fcnt; 
            } else if (s[i] == '(') {
                ++cnt;
            } else {
                --cnt;
            }
            if (cnt < 0) {
                if (fcnt > 0) {
                    --fcnt;
                    ++cnt;
                } else {
                    return false;
                }
            }
        }
        int closeCount = 0;
        fcnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                ++fcnt;
            } else if (s[i] == ')') {
                ++closeCount;
            } else {
                --closeCount;
            }
            if (closeCount < 0) {
                if (fcnt > 0) {
                    --fcnt;
                    ++closeCount;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
