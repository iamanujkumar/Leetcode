class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorres= start^goal;
        int count=0;
        while(xorres>0){
            count += xorres&1;
            xorres>>=1;
        }
        return count;
    }
};