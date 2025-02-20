class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        result += (nums[i][i] == '0') ? '1' : '0';
    }
    
    return result;
    }
};