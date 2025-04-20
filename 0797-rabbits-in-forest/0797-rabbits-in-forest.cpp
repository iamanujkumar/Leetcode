class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int ans : answers) {
            freq[ans]++;
        }
        int total = 0;
        for (auto& [x, count] : freq) {
            int gp = x + 1;
            int grp = (count + x) / gp;
            total += grp * gp;
        }
        return total;
    }
};
