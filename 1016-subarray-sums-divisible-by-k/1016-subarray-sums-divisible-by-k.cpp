#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;
        int sum = 0, ans = 0;
        
        for (int num : nums) {
            sum += num;
            int remainder = ((sum % k) + k) % k;
            
            if (remainderCount.find(remainder) != remainderCount.end()) {
                ans += remainderCount[remainder];
            }
            
            remainderCount[remainder]++;
        }
        
        return ans;
    }
};
