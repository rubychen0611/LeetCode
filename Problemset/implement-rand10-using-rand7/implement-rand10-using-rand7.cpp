
// @Title: 用 Rand7() 实现 Rand10() (Implement Rand10() Using Rand7())
// @Author: rubychen0611
// @Date: 2021-03-03 16:44:06
// @Runtime: 8 ms
// @Memory: 8.1 MB

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {  
        int row, col, x;
        do{
            row = rand7();
            col = rand7();
            x = (row - 1) * 7 + col;
        }while(x > 40);
        return x % 10 + 1;
        
    }
};
