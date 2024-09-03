class Solution {
public:
    int getLucky(string s, int k) {
        string numStr;
        for (char c : s) {
            int pos = c - 'a' + 1;
            numStr += to_string(pos);
        }
        int cal = 0;
        for (char c : numStr) {
            cal += c - '0';
        }
        while (--k > 0) {
            int data = 0;
            while (cal > 0) {
                data += cal % 10;
                cal /= 10;
            }
            cal = data;
        }
        
        return cal;
    }
};
