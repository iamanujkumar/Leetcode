class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int maxDist = 0;
        
        for(int i = 1; i < arrays.size(); i++) {
            maxDist = max(maxDist, abs(arrays[i].back() - mini)); 
            maxDist = max(maxDist, abs(maxi - arrays[i][0]));
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }
        
        return maxDist;
    }
};
