class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        int n = skill.size();
        for(int i = 0; i < n; i++) {
            sum += skill[i];
        }
        if (sum % (n / 2) != 0) {
            return -1;
        }
        long long targetSum = sum / (n / 2);
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            if (skill[i] + skill[j] == targetSum) {
                ans += skill[i] * skill[j];
            } else {
                return -1;
            }
            i++;
            j--;
        }
        return ans;
    }
};
