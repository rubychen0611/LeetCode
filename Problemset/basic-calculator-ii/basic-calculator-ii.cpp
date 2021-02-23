
// @Title: 基本计算器 II (Basic Calculator II)
// @Author: rubychen0611
// @Date: 2021-02-12 23:45:08
// @Runtime: 12 ms
// @Memory: 17.9 MB

enum TokenType{NUMBER, OPERATOR};
enum OPType{PLUS, SUB, MUL, DIV};
struct Token
{
    TokenType token_type;
    union 
    {
        OPType op_type;
        int number;
    } content;
    Token(int num)
    {
        token_type = NUMBER;
        content.number = num;
    }
    Token(OPType op)
    {
        token_type = OPERATOR;
        content.op_type = op;
    }
    
};
class Solution {
private:
    int findPlusSub(vector<Token> &tokens, int start, int end)
    {
        for(int i = end; i >= start; i--)
            if(tokens[i].token_type == OPERATOR && (tokens[i].content.op_type == PLUS || tokens[i].content.op_type == SUB))
                return i;
        return -1;
    }
    int findMulDiv(vector<Token> &tokens, int start, int end)
    {
        for(int i = end; i >= start; i--)
            if(tokens[i].token_type == OPERATOR && (tokens[i].content.op_type == MUL || tokens[i].content.op_type == DIV))
                return i;
        return -1;
    }
    int cal(vector<Token> &tokens, int start, int end)
    {
        if(start == end)
        {
            if(tokens[start].token_type == NUMBER)
                return tokens[start].content.number;
            return -1;
        }
        int idx;
        idx = findPlusSub(tokens, start, end);
        if(idx != -1)
        {
            if(tokens[idx].content.op_type == PLUS)
                 return cal(tokens, start, idx - 1) + cal(tokens, idx + 1, end);
            else
                return cal(tokens, start, idx - 1) - cal(tokens, idx + 1, end);
        }   
        idx = findMulDiv(tokens, start, end);
        if(idx != -1)
        {    
            if(tokens[idx].content.op_type == MUL)
                return cal(tokens, start, idx - 1) * cal(tokens, idx + 1, end);
            else
                return cal(tokens, start, idx - 1) / cal(tokens, idx + 1, end);
        }
        return -1;
    }
public:
    int calculate(string s) {
        vector<Token> tokens;
        string number_str = "";
        for(int i = 0; i < s.length(); i++)
        {
            
            if(s[i]>= '0' && s[i] <= '9')
                number_str += s[i];
            else
            {
                if(number_str != "")
                {
                    int number = stoi(number_str);
                    number_str = "";
                    tokens.push_back(Token(number));
                }
                switch(s[i])
                {
                    case '+': tokens.push_back(Token(PLUS)); break;
                    case '-': tokens.push_back(Token(SUB)); break;
                    case '*': tokens.push_back(Token(MUL)); break;
                    case '/': tokens.push_back(Token(DIV)); break;
                    default: break;
                }
            }
        }
        if(number_str != "")
        {
            int number = stoi(number_str);
            tokens.push_back(Token(number));
        }

        return cal(tokens, 0, tokens.size() - 1);
         
    }
};
