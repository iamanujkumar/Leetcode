class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> vec(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                cnt = n;
            } else if (dominoes[i] == 'L') {
                cnt = 0;
            } else {
                cnt = max(cnt - 1, 0);
            }
            vec[i] += cnt;
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                cnt = n;
            } else if (dominoes[i] == 'R') {
                cnt = 0;
            } else {
                cnt = max(cnt - 1, 0);
            }
            vec[i] -= cnt;
        }
        string result = "";
        for (int f : vec) {
            if (f > 0)
                result += 'R';
            else if (f < 0)
                result += 'L';
            else
                result += '.';
        }
        return result;
    }
};
