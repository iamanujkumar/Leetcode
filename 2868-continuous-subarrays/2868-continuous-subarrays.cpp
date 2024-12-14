#include <vector>
#include <set>

class Solution {
public:
    long long continuousSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        int st = 0;
        std::multiset<int> window;
        for (int end = 0; end < n; ++end) {
            window.insert(nums[end]);
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[st]));
                ++st;
            }
            cnt += (end - st + 1);
        }
        return cnt;
    }
};
