
// @Title: 平方数之和 (Sum of Square Numbers)
// @Author: rubychen0611
// @Date: 2021-01-04 15:30:34
// @Runtime: 36 ms
// @Memory: 24.8 MB

class Solution {
private:
    bool twoSum(vector<long long int>& numbers, long long int target) { // 167：两数之和（双指针）
        int i = 0, j = numbers.size() - 1;
        while(i <= j)   // i可以等于j
        {
            if(numbers[i] + numbers[j] == target)
                return true;
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
public:
    bool judgeSquareSum(int c)
    {
        vector<long long int> squares;
        for (int i = 0; i <= sqrt(c); i++)  // 0也算
            squares.push_back(i * i);
        return twoSum(squares, c);
    }
};

