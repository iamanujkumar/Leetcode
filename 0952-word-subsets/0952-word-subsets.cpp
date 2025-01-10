class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); 
        for (const string& word : words2) {
            vector<int> freq = countFrequencies(word);
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        vector<string> cal;
        for (const string& word : words1) {
            vector<int> freq = countFrequencies(word);
            if (isUniversal(freq, maxFreq)) {
                cal.push_back(word);
            }
        }

        return cal;
    }
private:
    vector<int> countFrequencies(const string& word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        return freq;
    }
    bool isUniversal(const vector<int>& wordFreq, const vector<int>& maxFreq) {
        for (int i = 0; i < 26; ++i) {
            if (wordFreq[i] < maxFreq[i]) {
                return false;
            }
        }
        return true;
    }
};
