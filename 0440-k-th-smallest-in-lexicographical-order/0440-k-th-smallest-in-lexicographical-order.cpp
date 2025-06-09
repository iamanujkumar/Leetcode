class Solution {
public:
    int findKthNumber(int n, int k) {
        int crr = 1;
        k--;
        while (k > 0) {
            int cnt = getcnt(n, crr); 
            if (cnt <= k) {
                crr++;
                k -= cnt;
            } else {
                crr *= 10;
                k--;
            }
        }

        return crr;
    }

private:
    int getcnt(int n, int prfx) {
        long long crr = prfx;
        long long nxt = prfx + 1;
        int cnt = 0;

        while (crr <= n) {
            cnt += min(n + 1LL, nxt) - crr; 
            crr *= 10;
            nxt *= 10;
        }

        return cnt;
    }
};
