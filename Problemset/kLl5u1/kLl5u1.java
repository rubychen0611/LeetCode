
// @Title: 排序数组中两个数字之和 (排序数组中两个数字之和)
// @Author: rubychen0611
// @Date: 2021-08-30 21:07:59
// @Runtime: 1 ms
// @Memory: 38.5 MB

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int p1 = 0, p2 = numbers.length - 1;
        while(p1 < p2)
        {
            int sum = numbers[p1] + numbers[p2];
            if (sum == target)
                return new int [] {p1, p2};
            else if (sum < target)
                p1 ++;
            else
                p2 --;
        }
        return new int[] {-1,-1};
    }
}
