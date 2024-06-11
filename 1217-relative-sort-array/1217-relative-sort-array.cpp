#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order;
        for (int i = 0; i < arr2.size(); ++i) {
            order[arr2[i]] = i;
        }
        vector<int> part1, part2;
        for (int num : arr1) {
            if (order.find(num) != order.end()) {
                part1.push_back(num);
            } else {
                part2.push_back(num);
            }
        }
    
        sort(part1.begin(), part1.end(), [&order](int a, int b) {
            return order[a] < order[b];
        });
        sort(part2.begin(), part2.end());
        part1.insert(part1.end(), part2.begin(), part2.end());
        
        return part1;
    }
};
