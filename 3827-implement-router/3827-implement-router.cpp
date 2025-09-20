#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source, destination, timestamp;
};

struct PacketHash {
    size_t operator()(const tuple<int,int,int>& t) const {
        auto [s, d, ts] = t;
        return hash<long long>()(((long long)s << 42) ^ ((long long)d << 21) ^ ts);
    }
};

class Router {
private:
    int memoryLimit;
    deque<Packet> q; 
    unordered_set<tuple<int,int,int>, PacketHash> seen;

    struct DestData {
        vector<int> timestamps; // always sorted
        int startIndex = 0;     // points to first valid timestamp
    };

    unordered_map<int, DestData> destToTimestamps;

    void evictOldest() {
        if (q.empty()) return;
        Packet old = q.front();
        q.pop_front();
        seen.erase({old.source, old.destination, old.timestamp});
        auto &d = destToTimestamps[old.destination];
        if (d.startIndex < (int)d.timestamps.size() && d.timestamps[d.startIndex] == old.timestamp) {
            d.startIndex++; // just skip instead of erase
        }
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> key = {source, destination, timestamp};
        if (seen.count(key)) return false;

        if ((int)q.size() == memoryLimit) {
            evictOldest();
        }

        q.push_back({source, destination, timestamp});
        seen.insert(key);
        destToTimestamps[destination].timestamps.push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet pkt = q.front();
        q.pop_front();
        seen.erase({pkt.source, pkt.destination, pkt.timestamp});

        auto &d = destToTimestamps[pkt.destination];
        if (d.startIndex < (int)d.timestamps.size() && d.timestamps[d.startIndex] == pkt.timestamp) {
            d.startIndex++;
        }

        return {pkt.source, pkt.destination, pkt.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destToTimestamps.count(destination)) return 0;
        auto &d = destToTimestamps[destination];
        auto &arr = d.timestamps;

        // skip invalid entries at front
        int L = d.startIndex;
        if (L >= (int)arr.size()) return 0;

        // binary search range [L .. end)
        auto it1 = lower_bound(arr.begin() + L, arr.end(), startTime);
        auto it2 = upper_bound(arr.begin() + L, arr.end(), endTime);
        return it2 - it1;
    }
};
