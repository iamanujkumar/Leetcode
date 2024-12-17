class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Frequency map to count occurrences of characters
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Max heap to sort characters lexicographically largest first
        priority_queue<pair<char, int>> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push({ch, count});
        }
        string result = "";
        while (!maxHeap.empty()) {
            auto [currChar, currCount] = maxHeap.top();
            maxHeap.pop();
            
            int useCount = min(currCount, repeatLimit);
            result.append(useCount, currChar);         
            currCount -= useCount;                 
            
            if (currCount > 0) { // If we still have more of this character to use
                if (maxHeap.empty()) {
                    break; // No way to break the sequence; exit early
                }
                auto [nextChar, cnt] = maxHeap.top();
                maxHeap.pop();
                
                result += nextChar; // Use one of the next character
                cnt--;  
                maxHeap.push({currChar, currCount});
                if (cnt > 0) {
                    maxHeap.push({nextChar, cnt});
                }
            }
        }
        return result;
    }
};
