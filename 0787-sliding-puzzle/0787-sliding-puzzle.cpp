#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450"; // Target state
        string start = ""; // Flatten the board into a string
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start += to_string(board[i][j]);
            }
        }
        
        // Define possible moves based on the zero index
        vector<vector<int>> neighbors = {
            {1, 3},    // Index 0
            {0, 2, 4}, // Index 1
            {1, 5},    // Index 2
            {0, 4},    // Index 3
            {1, 3, 5}, // Index 4
            {2, 4}     // Index 5
        };
        
        // BFS setup
        queue<pair<string, int>> q; // Pair of current state and move count
        unordered_set<string> visited; // To track visited states
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            
            // Check if the current state is the target
            if (curr == target) {
                return moves;
            }
            
            // Find the index of '0' in the current state
            int zeroIndex = curr.find('0');
            
            // Try all possible moves
            for (int neighbor : neighbors[zeroIndex]) {
                string next = curr;
                swap(next[zeroIndex], next[neighbor]);
                
                // If the new state has not been visited, process it
                if (!visited.count(next)) {
                    q.push({next, moves + 1});
                    visited.insert(next);
                }
            }
        }
        
        // If the target state is not reachable
        return -1;
    }
};
