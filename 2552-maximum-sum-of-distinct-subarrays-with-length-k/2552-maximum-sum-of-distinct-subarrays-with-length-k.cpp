#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> vex;
        long long maxi = 0, currentSum = 0;
        int start = 0;
        for (int end = 0; end < nums.size(); ++end) {
            currentSum += nums[end];
            vex[nums[end]]++;
            while (end - start + 1 > k) {
                currentSum -= nums[start];
                vex[nums[start]]--;
                if (vex[nums[start]] == 0) {
                    vex.erase(nums[start]);
                }
                start++;
            }
            if (end - start + 1 == k && vex.size() == k) {
                maxi = max(maxi, currentSum);
            }
        }
        return maxi;
    }
};
