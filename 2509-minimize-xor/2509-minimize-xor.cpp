class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int sbc = __builtin_popcount(num2);
        int cnt = 0;
        for (int i = 31; i >= 0 && sbc > 0; --i) {
            if ((num1 >> i) & 1) {
                cnt |= (1 << i);
                --sbc;
            }
        }
        for (int i = 0; i < 32 && sbc > 0; ++i) {
            if (!((cnt >> i) & 1)) {
                cnt |= (1 << i);
                --sbc;
            }
        }
        return cnt;
    }
};
