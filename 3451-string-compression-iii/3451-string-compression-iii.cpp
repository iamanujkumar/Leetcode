class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        int i = 0;
        while (i < n) {
            char c = word[i];
            int cnt = 0;
            while (i < n && word[i] == c && cnt < 9) {
                cnt++;
                i++;
            }
            comp += to_string(cnt) + c;
        }
        return comp;
    }
};