class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
        }
        long long score = 0;
        for (int i = 0; i < k; ++i) {
            int topElement = pq.top();
            pq.pop();
            score += topElement;
            int temp = ceil(topElement / 3.0);
            pq.push(temp);
        }
        return score;
    }
};