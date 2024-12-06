class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxi) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        int sum = 0, count = 0;
        for (int i = 1; i <= n; ++i) {
            if (bannedSet.find(i) != bannedSet.end()) {
                continue;
            }
            if (sum + i > maxi) {
                break;
            }
            sum += i;
            ++count;
        }
        return count;
    }
};