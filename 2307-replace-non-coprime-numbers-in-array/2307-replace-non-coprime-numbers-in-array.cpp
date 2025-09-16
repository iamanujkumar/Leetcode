class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int num : nums) {
            long long curr = num;
            while (!st.empty()) {
                long long g = gcd(st.back(), curr);
                if (g == 1) break;
                curr = lcm(st.back(), curr);
                st.pop_back();
            }
            st.push_back((int)curr);
        }
        return st;
    }

private:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
};
