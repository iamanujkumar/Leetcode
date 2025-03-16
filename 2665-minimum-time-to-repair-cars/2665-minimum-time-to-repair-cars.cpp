class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;
        for (int r : ranks) {
            totalCars += sqrt(mid / r);
            if (totalCars >= cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long st = 1;
        long long e = *min_element(ranks.begin(), ranks.end()) * 1LL * cars * cars;
        long long ans = e;
        
        while (st <= e) {
            long long mid = st + (e - st) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};
