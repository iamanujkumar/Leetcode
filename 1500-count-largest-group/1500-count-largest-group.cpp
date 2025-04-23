class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            mp[sum]++;
        }
        int maxSize = 0;
        for (auto& pair : mp) {
            maxSize = max(maxSize, pair.second);
        }
        int result = 0;
        for (auto& pair : mp) {
            if (pair.second == maxSize) {
                result++;
            }
        }

        return result;
    }
private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
