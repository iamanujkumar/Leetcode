class Solution {
    void evaluate(stack<char>& optr, stack<char>& itr) {
        char op = optr.top();  // Get the operator at the top
        optr.pop();            // Remove the operator from stack

        bool ans;

        if (op == '|') {
            ans = false; // For OR, initial value should be false
            while (itr.top() != '(') {
                ans |= (itr.top() == 't');
                itr.pop();
            }
            itr.pop();  // Pop the '('
        } 
        else if (op == '&') {
            ans = true;  // For AND, initial value should be true
            while (itr.top() != '(') {
                ans &= (itr.top() == 't');
                itr.pop();
            }
            itr.pop();  // Pop the '('
        } 
        else if (op == '!') {
            ans = (itr.top() == 't');
            ans = !ans;   // Negate the value
            itr.pop();  // Pop the value
            itr.pop();  // Pop the '('
        }

        if (ans) itr.push('t');  // Push true result back to itr stack
        else     itr.push('f');  // Push false result back to itr stack
    }

public:
    bool parseBoolExpr(string expression) {
        stack<char> optr, itr;
        int idx = 0;

        while (expression[idx]) {
            if (expression[idx] == '!' || expression[idx] == '&' || expression[idx] == '|') {
                optr.push(expression[idx]);  // Push operators
            } 
            else if (expression[idx] == 't' || expression[idx] == 'f') {
                itr.push(expression[idx]);  // Push itrs
            } 
            else if (expression[idx] == '(') {
                itr.push(expression[idx]);  // Push opening parentheses
            } 
            else if (expression[idx] == ')') {
                evaluate(optr, itr);  // Evaluate when closing parenthesis is encountered
            }
            idx++;
        }
        return itr.top() == 't';  // Final result check
    }
};