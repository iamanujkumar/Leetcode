class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long gap = 0;
        long long min_val = 0;
        long long max_val = 0;
        long long curr_val = 0;
        for(int& ele: differences){
            curr_val += ele;
            min_val = min(min_val,curr_val);
            max_val = max(max_val,curr_val);
        }
        int count = (upper-lower) - (max_val-min_val) + 1;
        return count>0? count : 0;
    }
};