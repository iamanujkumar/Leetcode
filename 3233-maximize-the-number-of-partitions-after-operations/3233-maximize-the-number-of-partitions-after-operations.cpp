#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<array<int,3>> left(n), right(n);

        int partitions = 0, mask = 0, distinct = 0;
        for (int i = 0; i < n - 1; i++) {
            int bit = 1 << (s[i] - 'a');
            if ((mask & bit) == 0) {
                distinct++;
                if (distinct <= k) mask |= bit;
                else {
                    partitions++;
                    mask = bit;
                    distinct = 1;
                }
            }
            left[i+1] = {partitions, mask, distinct};
        }

        partitions = 0; mask = 0; distinct = 0;
        for (int i = n-1; i > 0; i--) {
            int bit = 1 << (s[i] - 'a');
            if ((mask & bit) == 0) {
                distinct++;
                if (distinct <= k) mask |= bit;
                else {
                    partitions++;
                    mask = bit;
                    distinct = 1;
                }
            }
            right[i-1] = {partitions, mask, distinct};
        }

        int maxPartitions = 0;
        for (int i = 0; i < n; i++) {
            int total = left[i][0] + right[i][0] + 2;
            int combinedMask = left[i][1] | right[i][1];
            int combinedDistinct = __builtin_popcount(combinedMask);

            if (left[i][2] == k && right[i][2] == k && combinedDistinct < 26) total++;
            else if (min(combinedDistinct + 1, 26) <= k) total--;

            maxPartitions = max(maxPartitions, total);
        }

        return maxPartitions;
    }
};
