#include <string>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        string st1, s2;
        for (char c : start) {
            if (c != '_') st1 += c;
        }
        for (char c : target) {
            if (c != '_') s2 += c;
        }
        if (st1 != s2) return false;
        int startIndex = 0, targetIndex = 0;
        while (startIndex < start.size() && targetIndex < target.size()) {
            if (start[startIndex] == '_') {
                startIndex++;
                continue;
            }
            if (target[targetIndex] == '_') {
                targetIndex++;
                continue;
            }
            if (start[startIndex] == 'L') {
                if (startIndex < targetIndex) return false;
            }
            if (start[startIndex] == 'R') {
                if (startIndex > targetIndex) return false;
            }
            startIndex++;
            targetIndex++;
        }
        return true;
    }
};
