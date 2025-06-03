class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasKey(n, false), used(n, false);
        vector<bool> boxAvailable(n, false);
        queue<int> q;

        for (int box : initialBoxes) {
            boxAvailable[box] = true;
            if (status[box]) q.push(box);
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (used[curr]) continue; // skip if already processed
            used[curr] = true;
            totalCandies += candies[curr];

            // Add new keys and check if they open new boxes
            for (int key : keys[curr]) {
                hasKey[key] = true;
                if (boxAvailable[key] && !used[key]) {
                    q.push(key);
                }
            }
            for (int box : containedBoxes[curr]) {
                boxAvailable[box] = true;
                if (status[box] || hasKey[box]) {
                    q.push(box);
                }
            }
        }

        return totalCandies;
    }
};
