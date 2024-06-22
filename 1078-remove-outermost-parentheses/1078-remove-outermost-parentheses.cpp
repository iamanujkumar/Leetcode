class Solution {
public:
    string removeOuterParentheses(string s) {
        string str = "";
        int count = 0; 
        
        for(char c : s) {
            if(c == '(') {
                if(count > 0) {
                    str += c; 
                }
                count++;
            } else if(c == ')') {
                count--;
                if(count > 0) {
                    str += c;
                }
            }
        }
        
        return str;
    }
};
