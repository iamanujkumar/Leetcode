class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevLast = INT_MIN;

            for (int i = 0; i < n && valid; i += k) {
                int descents = 0, cut = 0;

                for (int j = 0; j < k; ++j) {
                    int next = (j + 1) % k;
                    if (nums[i + j] > nums[i + next]) {
                        ++descents;
                        cut = next;
                    }
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                int first = nums[i + cut];
                int last = nums[i + (cut + k - 1) % k];

                if (first < prevLast) {
                    valid = false;
                    break;
                }

                prevLast = last;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};