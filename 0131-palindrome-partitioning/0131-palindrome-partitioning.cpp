class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void fun(string &s, int i, vector<string>& currPartition, vector<vector<string>>& result) {
        if (i == s.size()) {
            result.push_back(currPartition);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                currPartition.push_back(s.substr(i, j - i + 1)); 
                fun(s, j + 1, currPartition, result);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currPartition;
        fun(s, 0, currPartition, result); 
        return result;
    }
};
