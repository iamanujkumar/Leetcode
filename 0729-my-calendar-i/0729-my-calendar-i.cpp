class MyCalendar {
public:
    vector<pair<int, int>> bookings;
    MyCalendar() {
    }
    bool book(int start, int end) {
        for (auto &it : bookings) {
            int bks = it.first;
            int bookedEnd = it.second;
            if (start < bookedEnd && bks < end) {
                return false;
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */