class Solution {
public:
    long long prefix(long long n) {
        if (n <= 0) return 0;
        long long ans = 0;
        long long k = 0;
        long long base = 1; 
        while (base <= n) {
            long long nextBase = base * 4;
            long long high = min(n, nextBase - 1);
            long long count = high - base + 1;
            ans += count * (k + 1);
            base = nextBase;
            k++;
        }
        return ans;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long total = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long sumSteps = prefix(r) - prefix(l - 1);
            total += (sumSteps + 1) / 2; 
        }
        return total;
    }
};
