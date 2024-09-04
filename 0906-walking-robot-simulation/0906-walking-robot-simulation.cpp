class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
        int x = 0, y = 0;
        int directionIndex = 0;
        int maxDistanceSquared = 0;
        for (const auto& command : commands) {
            if (command == -2) {
                directionIndex = (directionIndex + 3) % 4;
            } else if (command == -1) {
                directionIndex = (directionIndex + 1) % 4;
            } else {
                for (int step = 0; step < command; ++step) {
                    int nextX = x + directions[directionIndex].first;
                    int nextY = y + directions[directionIndex].second;
                    if (obstacleSet.find(to_string(nextX) + "," + to_string(nextY)) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        
        return maxDistanceSquared;
    }
};
