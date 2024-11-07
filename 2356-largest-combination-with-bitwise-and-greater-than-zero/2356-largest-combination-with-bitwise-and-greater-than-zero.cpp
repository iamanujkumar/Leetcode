#include <vector>
#include <algorithm>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int maxi = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int it : candidates) {
                if (it & (1 << bit)) {
                    count++;
                }
            }
            maxi = std::max(maxi, count);
        }
        return maxi;
    }
};
