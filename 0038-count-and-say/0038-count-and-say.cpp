
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 2; i <= n; ++i) {
            string current = "";
            int len = result.length();
            
            for (int j = 0; j < len; ) {
                char ch = result[j];
                int count = 0;
                
                // Count the number of same characters in a row
                while (j < len && result[j] == ch) {
                    ++j;
                    ++count;
                }
                
                // Append count followed by the character
                current += to_string(count) + ch;
            }
            
            result = current; // Move to the next iteration
        }
        
        return result;
    }
};
