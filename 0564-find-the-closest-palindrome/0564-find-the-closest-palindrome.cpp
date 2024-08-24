class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        set<long long> candidates;
        candidates.insert(pow(10, len - 1) - 1);
        candidates.insert(pow(10, len) + 1);
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        
        for (int i = -1; i <= 1; i++) {
            string newPrefix = to_string(prefix + i);
            string candidate = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());
            candidates.insert(stoll(candidate));
        }
        candidates.erase(num);        
        long long closest = -1;
        for (long long candidate : candidates) {
            if (closest == -1 || abs(candidate - num) < abs(closest - num) || 
                (abs(candidate - num) == abs(closest - num) && candidate < closest)) {
                closest = candidate;
            }
        }
        
        return to_string(closest);
    }
};
