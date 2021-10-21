
// @Title: 后缀表达式 (后缀表达式)
// @Author: rubychen0611
// @Date: 2021-10-10 23:18:37
// @Runtime: 12 ms
// @Memory: 11.7 MB

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
