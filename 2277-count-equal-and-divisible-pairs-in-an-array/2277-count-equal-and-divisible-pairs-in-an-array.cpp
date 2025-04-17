class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }
        for (auto& pair : mp) {
            vector<int>& indices = pair.second;
            for (int i = 0; i < indices.size(); ++i) {
                for (int j = i + 1; j < indices.size(); ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
