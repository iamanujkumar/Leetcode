class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 0;
        while (ss >> word) {
            index++;
            if (word.find(searchWord) == 0) {
                return index;
            }
        }
        return -1;
    }
};