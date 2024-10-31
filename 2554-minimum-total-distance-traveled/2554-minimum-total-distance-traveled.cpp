#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 0; 
                for (int i = 1; i <= n; ++i) {
                dp[i][j] = dp[i][j - 1]; 
                long long cost = 0;
                for (int k = 1; k <= factory[j - 1][1] && k <= i; ++k) {
                    cost += abs(factory[j - 1][0] - robot[i - k]); 
                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                    }
                }
            }
        }
        return dp[n][m];
    }
};
