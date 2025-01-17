class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        auto isValid = [&](int start) {
            vector<int> v(n);
            v[0] = start;
            for (int i = 1; i < n; ++i) {
                v[i] = derived[i - 1] ^ v[i - 1];
            }
            return (v[n - 1] ^ v[0]) == derived[n - 1];
        };
        return isValid(0) || isValid(1);
    }
};
