#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    struct Task {
        int priority;
        int taskId;
        int userId;
    };
    
    struct Compare {
        bool operator()(const Task& a, const Task& b) const {
            if (a.priority == b.priority) 
                return a.taskId < b.taskId; 
            return a.priority < b.priority; 
        }
    };
    
    priority_queue<Task, vector<Task>, Compare> pq;
    unordered_map<int, pair<int,int>> taskInfo; 
    
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int u = t[0], id = t[1], p = t[2];
            taskInfo[id] = {u, p};
            pq.push({p, id, u});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [u, _] = taskInfo[taskId];
        taskInfo[taskId] = {u, newPriority};
        pq.push({newPriority, taskId, u});
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId); 
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            if (taskInfo.count(top.taskId) && taskInfo[top.taskId].second == top.priority) {
                int userId = taskInfo[top.taskId].first;
                taskInfo.erase(top.taskId);
                return userId;
            }
        }
        return -1;
    }
};
