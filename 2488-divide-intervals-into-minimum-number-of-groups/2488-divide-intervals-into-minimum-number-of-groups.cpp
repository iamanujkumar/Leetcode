class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> diff(1e6+5, 0);
        for(auto& interval : intervals) {
            diff[interval[0]]++;   
            diff[interval[1] + 1]--; 
        }
        int max_overlap = 0;
        int overlap = 0;
        for(int i = 0; i < 1e6+5; ++i) {
            overlap += diff[i];
            max_overlap = max(max_overlap, overlap);
        }
        return max_overlap;
    }
};