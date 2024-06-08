#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> rem;
        rem[0] = -1; 
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainder < 0) {
                remainder += k;
            }
            
            if (rem.find(remainder) != rem.end()) {
                if (i - rem[remainder] > 1) {
                    return true;
                }
            } else {
                rem[remainder] = i;
            }
        }
        
        return false;
    }
};
