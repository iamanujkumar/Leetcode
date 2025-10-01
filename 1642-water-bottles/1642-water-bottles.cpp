class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    int count = 0;
    int empty = 0;
    while (numBottles > 0) {
        count += numBottles;
        empty += numBottles;
        numBottles = empty / numExchange;
        empty = empty % numExchange;
    }
    return count;
}
};