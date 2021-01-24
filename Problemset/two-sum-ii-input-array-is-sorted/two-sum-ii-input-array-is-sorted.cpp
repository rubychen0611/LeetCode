
// @Title: 两数之和 II - 输入有序数组 (Two Sum II - Input array is sorted)
// @Author: rubychen0611
// @Date: 2021-01-04 11:17:16
// @Runtime: 12 ms
// @Memory: 9.6 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> ans(2);
        while(i < j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return ans;
    }
};

