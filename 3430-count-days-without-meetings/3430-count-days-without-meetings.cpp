class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> merged;
        for (auto& meeting : meetings) {
            if (!merged.empty() && merged.back()[1] >= meeting[0] - 1) {
                merged.back()[1] = max(merged.back()[1], meeting[1]);
            } else {
                merged.push_back(meeting);
            }
        }
        int avl = 0;
        if (merged[0][0] > 1) {
            avl += merged[0][0] - 1;
        }

        for (int i = 1; i < merged.size(); ++i) {
            avl += merged[i][0] - merged[i - 1][1] - 1;
        }

        if (merged.back()[1] < days) {
            avl += days - merged.back()[1];
        }
        return avl;
    }
};
