class Solution {
public:
    unordered_map<string, vector<int>> mp;
    
    vector<int> diffWaysToCompute(string expression) {

        if (mp.find(expression) != mp.end()) {
            return mp[expression];
        }
        
        vector<int> result;
        bool flag = true;

        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                flag = false;

                string start = expression.substr(0, i);
                string end = expression.substr(i + 1);

                vector<int> startResults = diffWaysToCompute(start);
                vector<int> endResults = diffWaysToCompute(end);

                for (int it : startResults) {
                    for (int endVal : endResults) {
                        if (expression[i] == '+') {
                            result.push_back(it + endVal);
                        } else if (expression[i] == '-') {
                            result.push_back(it - endVal);
                        } else if (expression[i] == '*') {
                            result.push_back(it * endVal);
                        }
                    }
                }
            }
        }

        if (flag) {
            result.push_back(stoi(expression));
        }

        mp[expression] = result;
        return result;
    }
};
