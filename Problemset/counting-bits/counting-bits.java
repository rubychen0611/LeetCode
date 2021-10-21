
// @Title: 比特位计数 (Counting Bits)
// @Author: rubychen0611
// @Date: 2021-08-29 20:53:30
// @Runtime: 1 ms
// @Memory: 42.5 MB

class Solution {
    public int[] countBits(int n) {
        int[] result = new int [n + 1];
        result[0] = 0;
        for(int i = 1 ; i <= n; i++)
        {
            if(i % 2 == 1)
                result[i] = result[i >> 1] + 1;
            else
                result[i] = result[i >> 1];
        }
        return result;
    }
}
