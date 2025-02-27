class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> indexMap;
        unordered_map<int, int> dp;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int x = arr[j] - arr[i]; 
                if (indexMap.count(x) && indexMap[x] < i) {
                    int k = indexMap[x];
                    int key = k * n + i;
                    int length = dp.count(key) ? dp[key] + 1 : 3; 
                    dp[i * n + j] = length;
                    maxLength = max(maxLength, length);
                }
            }
        }
        return maxLength;
    }
};
