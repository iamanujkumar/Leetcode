class Solution {
public:
    long long getGcd(long long a, long long b) {
        if (b == 0)
            return a;
        return getGcd(b, a % b);
    }

    string fractionAddition(string expression) {
        long long numerator = 0, denominator = 1;
        int i = 0;
        int n = expression.size();
        while (i < n) {
            int currNum = 0, currDen = 0;
            bool isNeg = false;
            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') isNeg = true;
                i++;
            }
            int s = i;
            while (i < n && isdigit(expression[i])) {
                i++;
            }
            currNum = stoi(expression.substr(s, i - s));
            if (isNeg) currNum = -1 * currNum;
            i++;

            s = i;
            while (i < n && isdigit(expression[i])) {
                i++;
            }
            currDen = stoi(expression.substr(s, i - s));
            numerator = numerator * currDen + currNum * denominator;
            denominator = denominator * currDen;
        }

        long long gcd = abs(getGcd(numerator, denominator));
        numerator /= gcd;
        denominator /= gcd;
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
