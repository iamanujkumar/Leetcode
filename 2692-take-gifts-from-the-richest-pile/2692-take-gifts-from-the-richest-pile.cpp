class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        for (int gift : gifts) {
            maxHeap.push(gift);
        }
        while (k-- > 0 && !maxHeap.empty()) {
            int largestPile = maxHeap.top();
            maxHeap.pop();
            int remainingGifts = floor(sqrt(largestPile));
            maxHeap.push(remainingGifts);
        }
        long long st = 0;
        while (!maxHeap.empty()) {
            st += maxHeap.top();
            maxHeap.pop();
        }
        return st;
    }
};