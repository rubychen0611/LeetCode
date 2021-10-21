
// @Title: 数组中数字出现的次数 (数组中数字出现的次数 LCOF)
// @Author: rubychen0611
// @Date: 2021-08-30 00:04:09
// @Runtime: 4 ms
// @Memory: 39.9 MB

class Solution {
    public int[] singleNumbers(int[] nums) {
        int x = 0;
        for(int num: nums)
            x ^= num;
        int f = 1; // f第i位为1
        for(int i = 0; i < 32; i ++)
        {
            if ((x & f) != 0)
                break;
            f <<= 1;
        }
        ArrayList<Integer> array1 = new ArrayList<Integer>();
        ArrayList<Integer> array2 = new ArrayList<Integer>();
        for(int num: nums)
        {
            if ((num & f)  != 0)
                array1.add(num);
            else
                array2.add(num);
        }
        int ans1 = 0, ans2 = 0;
        for(Integer num: array1)
            ans1 ^= num;
        for(Integer num: array2)
            ans2 ^= num;
        int[] ans = new int [2];
        ans[0] = ans1;
        ans[1] = ans2;
        return ans;
    }
}
