class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> px(n);
        px[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            px[i] = px[i - 1] ^ arr[i];
        }
        vector<int> ans;
        for (const auto& q : queries) {
            int left = q[0], right = q[1];
            if (left == 0) {
                ans.push_back(px[right]);
            } else {
                ans.push_back(px[right] ^ px[left - 1]);
            }
        }
        
        return ans;
    }
};
