class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> vec(n, 0);
        int balls = 0, ops = 0;
        for (int i = 0; i < n; ++i) {
            vec[i] += ops;
            balls += (boxes[i] == '1') ? 1 : 0;
            ops += balls;
        }
        balls = 0, ops = 0;
        for (int i = n - 1; i >= 0; --i) {
            vec[i] += ops;
            balls += (boxes[i] == '1') ? 1 : 0;
            ops += balls;
        }
        return vec;
    }
};
