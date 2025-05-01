class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());

        for (int i = k - 1; i >= 0; --i) { 
            int task = tasks[i];
            auto it = available.lower_bound(task);
            if (it != available.end()) {
                available.erase(it);
            } else {
                if (pills == 0) return false;
                it = available.lower_bound(task - strength);
                if (it == available.end()) return false;
                available.erase(it);
                --pills;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0, high = min(tasks.size(), workers.size()), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
