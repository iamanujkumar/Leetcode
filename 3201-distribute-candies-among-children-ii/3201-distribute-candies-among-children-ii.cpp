class Solution {
public:
    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= (n - i + 1);
            res /= i;
        }
        return res;
    }
    
    long long distributeCandies(int n, int limit) {
        long long total = nCk(n + 2, 2);
        long long subtract1 = 3 * nCk(n - (limit + 1) + 2, 2);
        long long add2 = 3 * nCk(n - 2 * (limit + 1) + 2, 2);
        long long subtract3 = nCk(n - 3 * (limit + 1) + 2, 2);
        return total - subtract1 + add2 - subtract3;
    }
};
