class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        auto calcXSum = [&](unordered_map<int, int>& freq) {
            vector<pair<int,int>> arr;
            for (auto& p : freq) arr.push_back(p);
            
            sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });   
            int sum = 0, cnt = 0;
            for (auto& p : arr) {
                if (cnt == x) break;
                sum += p.first * p.second;
                cnt++;
            }
            return sum;
        }; 
        ans.push_back(calcXSum(freq));
        for (int i = k; i < n; i++) {
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            freq[nums[i]]++;
            ans.push_back(calcXSum(freq));
        }
        return ans;
    }
};
