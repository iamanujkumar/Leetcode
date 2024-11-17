#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long, int>> dq;
        long prefix_sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            if (prefix_sum >= k) {
                res = min(res, i + 1);
            }
            while (!dq.empty() && prefix_sum - dq.front().first >= k) {
                res = min(res, i - dq.front().second);
                dq.pop_front();
            }
            while (!dq.empty() && dq.back().first >= prefix_sum) {
                dq.pop_back();
            }
            dq.emplace_back(prefix_sum, i);
        }
        return res == INT_MAX ? -1 : res;
    }
};
