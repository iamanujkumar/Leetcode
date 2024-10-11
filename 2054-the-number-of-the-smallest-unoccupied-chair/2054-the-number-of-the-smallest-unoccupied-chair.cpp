class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), times.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
        priority_queue<int, vector<int>, greater<int>> available;
        int chairNo = 0; 
        for (const auto& time : times) {
            int arrTime = time[0];
            int leavingTime = time[1];
            while (!occupied.empty() && occupied.top().first <= arrTime) {
                available.push(occupied.top().second);
                occupied.pop();
            }
            int currentChairNo;
            if (available.empty()) {
                currentChairNo = chairNo;
                chairNo++;
            } else {
                currentChairNo = available.top();
                available.pop();
            }
            if (targetArrival == arrTime) return currentChairNo;
            occupied.push({leavingTime, currentChairNo});
        }

        return -1;
    }
};
