#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto& [key, count] : mp) {
            if (count % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
