/*
150. Evaluate Reverse Polish Notation
Medium

468

330

Favorite

        Share
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would
 always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/


#include <stack>


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return -1;
        }

        stack<int> s;

        for (int i=0; i<tokens.size(); i++) {
            if (
                    tokens[i] == "+" or
                    tokens[i] == "-" or
                    tokens[i] == "*" or
                    tokens[i] == "/"
                    ) {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();

                if (tokens[i] == "+")
                    s.push(num2+num1);

                if (tokens[i] == "-")
                    s.push(num2-num1);

                if (tokens[i] == "*")
                    s.push(num2*num1);

                if (tokens[i] == "/")
                    s.push(num2/num1);
            }

            else {
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }
};
