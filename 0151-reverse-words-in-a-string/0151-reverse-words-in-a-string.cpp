class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        string temp = "";
        string ans = "";
        
        // Skip leading spaces
        while (left <= right && s[left] == ' ') left++;
        
        // Skip trailing spaces
        while (right >= left && s[right] == ' ') right--;
        
        // Iterate the string and keep on adding to form a word
        // If a space is encountered then add the current word to the result
        while (left <= right) {
            char ch = s[left];
            if (ch != ' ') {
                temp += ch;
            } else if (ch == ' ') {
                if (!temp.empty()) {
                    if (!ans.empty()) ans = temp + " " + ans;
                    else ans = temp;
                    temp = "";
                }
            }
            left++;
        }
        
        // If temp is not empty, add it to the result (Last word)
        if (!temp.empty()) {
            if (!ans.empty()) ans = temp + " " + ans;
            else ans = temp;
        }
        
        return ans;    
    }
};
