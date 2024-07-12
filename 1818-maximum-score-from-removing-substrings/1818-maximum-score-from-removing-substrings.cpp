class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> stack1, stack2;
        int ans = 0;
        bool f = x > y;

        for (char ch : s) {
            if (!stack1.empty()) {
                if (f) {
                    if (stack1.back() == 'a' && ch == 'b') {
                        ans += x;
                        stack1.pop_back();
                    } else {
                        stack1.push_back(ch);
                    }
                } else {
                    if (stack1.back() == 'b' && ch == 'a') {
                        ans += y;
                        stack1.pop_back();
                    } else {
                        stack1.push_back(ch);
                    }
                }
            } else {
                stack1.push_back(ch);
            }
        }

        for (char ch : stack1) {
            if (!stack2.empty()) {
                if (!f) {
                    if (stack2.back() == 'a' && ch == 'b') {
                        ans += x;
                        stack2.pop_back();
                    } else {
                        stack2.push_back(ch);
                    }
                } else {
                    if (stack2.back() == 'b' && ch == 'a') {
                        ans += y;
                        stack2.pop_back();
                    } else {
                        stack2.push_back(ch);
                    }
                }
            } else {
                stack2.push_back(ch);
            }
        }

        return ans;
    }
};