class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string st = s + s;
        return st.find(goal) != string::npos;
    }
};