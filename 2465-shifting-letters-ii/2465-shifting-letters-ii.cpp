class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            if (direction == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }
        int cumulativeShift = 0;
        for (int i = 0; i < n; i++) {
            cumulativeShift += diff[i];
            int shift = (cumulativeShift % 26 + 26) % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }
        return s;
    }
};
