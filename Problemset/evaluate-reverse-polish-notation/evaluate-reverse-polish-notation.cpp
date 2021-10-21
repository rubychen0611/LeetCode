
// @Title: 逆波兰表达式求值 (Evaluate Reverse Polish Notation)
// @Author: rubychen0611
// @Date: 2021-10-10 23:18:49
// @Runtime: 8 ms
// @Memory: 11.8 MB

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int ans = 0, tmp;
        for(string& token: tokens) {
            if (token.length() == 1 && (token[0] == '+' ||
            token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                    int num2 = numbers.top();
                    numbers.pop();
                    int num1 = numbers.top();
                    numbers.pop();
                    switch(token[0]) {
                        case '+': numbers.push(num1 + num2); break;
                        case '-': numbers.push(num1 - num2); break;
                        case '*': numbers.push(num1 * num2); break;
                        case '/': numbers.push(num1 / num2); break;
                    }
            }
            else {
                int num = atoi(token.c_str());
                numbers.push(num);
            }
        }
        return numbers.top();
    }
};
