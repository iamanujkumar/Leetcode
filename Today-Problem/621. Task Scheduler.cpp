class Solution {
public:
   int leastInterval(vector<char>& tasks, int n) {
    vector<int> v(26, 0);
    for (char task : tasks) {
        v[task - 'A']++;
    }
    sort(v.begin(), v.end(), greater<int>());
    int maxi = v[0]; 
    int idle = (maxi - 1) * n; 

    for (int i = 1; i < 26 && v[i] > 0; i++) {
        idle -= min(maxi - 1, v[i]); 
    }
    idle = max(0, idle); 
    return tasks.size() + idle; 
}
};