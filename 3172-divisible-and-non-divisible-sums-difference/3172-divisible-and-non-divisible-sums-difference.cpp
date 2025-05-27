class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = n * (n + 1) / 2;
        int cnt = n / m;
        int div = m * cnt * (cnt + 1) / 2;
        return total - 2 * div;
    }
};
