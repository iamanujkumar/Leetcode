#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1; // At least one group is needed
        int start = nums[0]; // Start of current subsequence
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - start > k) {
                count++;
                start = nums[i]; 
            }
        }
        
        return count;
    }
};
