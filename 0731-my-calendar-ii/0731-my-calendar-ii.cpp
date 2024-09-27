#include <vector>
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
    
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for (auto& [s, e] : overlaps) {
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }
        for (auto& [s, e] : booked) {
            int overlap_start = max(s, start);
            int overlap_end = min(e, end);
            if (overlap_start < overlap_end) {
                overlaps.push_back({overlap_start, overlap_end});
            }
        }
        booked.push_back({start, end});
        return true;
    }
};


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */