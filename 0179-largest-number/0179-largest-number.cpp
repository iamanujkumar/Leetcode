class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> st1;
        for (int num : nums) {
            st1.push_back(to_string(num));
        }
        sort(st1.begin(), st1.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        if (st1[0] == "0") {
            return "0";
        }
        string ans;
        for (const string &str : st1) {
            ans += str;
        }
        return ans;
    }
};
