class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int low = 1, high = n, cnt = -1;
        auto isSpecial = [](const string& str) {
            for (char c : str) {
                if (c != str[0]) return false;
            }
            return true;
        };
        auto isValid = [&](int len) {
            unordered_map<string, int> mp;
            for (int i = 0; i <= n - len; ++i) {
                string substring = s.substr(i, len);
                if (isSpecial(substring)) {
                    mp[substring]++;
                    if (mp[substring] >= 3) {
                        return true;
                    }
                }
            }
            return false;
        };
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                cnt = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return cnt;
    }
};
