class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = n * (n - 1) / 2;
        unordered_map<int, long long> countMap;
        long long goodPairs = 0;
        for (int j = 0; j < n; ++j) {
            int key = nums[j] - j;
            if (countMap.count(key)) {
                goodPairs += countMap[key];
            }
            countMap[key]++;
        }
        return totalPairs - goodPairs;
    }
};
