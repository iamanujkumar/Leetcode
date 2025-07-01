class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int count = 1; // count the original string itself

        for (int i = 0; i < n;) {
            int j = i;
            // move j to the end of the current character group
            while (j < n && word[j] == word[i]) {
                j++;
            }

            int len = j - i;

            // If group length >= 2, Alice might have held the key too long
            if (len >= 2) {
                count += (len - 1); // we can reduce this group in (len - 1) ways
            }

            i = j; // move to next group
        }

        return count;
    }
};
