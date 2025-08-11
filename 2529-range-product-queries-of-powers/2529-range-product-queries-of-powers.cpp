class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }
        int m = powers.size();
        vector<long long> prefix(m);
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i-1] * powers[i]) % MOD;
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                ans.push_back(prefix[r] % MOD);
            } else {
                long long inv = modPow(prefix[l-1], MOD - 2);
                ans.push_back((prefix[r] * inv) % MOD);
            }
        }
        return ans;
    }
};
