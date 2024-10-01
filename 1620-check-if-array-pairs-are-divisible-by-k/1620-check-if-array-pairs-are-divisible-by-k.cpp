class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        int rem = ((arr[i] % k) + k) % k;
        mp[rem]++;
    }
    
    for (auto it : mp) {
        int rem = it.first;
        if (rem == 0) {
            if (mp[rem] % 2 != 0) return false;
        } else {
            if (mp[rem] != mp[k - rem]) return false;
        }
    }
    
    return true;
}

};