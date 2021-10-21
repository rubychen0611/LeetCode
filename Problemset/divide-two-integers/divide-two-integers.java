
// @Title: 两数相除 (Divide Two Integers)
// @Author: rubychen0611
// @Date: 2021-08-29 19:43:06
// @Runtime: 1 ms
// @Memory: 35.6 MB

class Solution {
    public int divide(int a, int b) {
        if(a == 0x80000000 && b == -1)
            return 0x7fffffff;
        if (a == 0)
            return 0;
        int negative_count = 0;
        if (a < 0)
            negative_count ++;
        else
            a = -a;
        if (b < 0)
            negative_count ++;
        else
            b = -b;
        int result = divideCore(a, b);
        return negative_count == 1 ? -result : result;
    }
    private int divideCore(int a, int b) {
        int result = 0;
        while(a <= b) {
            int value = b;
            int times = 1;
            while (value >= 0xc0000000 && a <= value + value) {
                value += value;
                times += times;
            }
            result += times;
            a -= value;
        }
        return result;
    }
}
