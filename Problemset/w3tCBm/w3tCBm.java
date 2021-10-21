
// @Title: 前 n 个数字二进制中 1 的个数 (前 n 个数字二进制中 1 的个数)
// @Author: rubychen0611
// @Date: 2021-08-29 20:53:01
// @Runtime: 1 ms
// @Memory: 42 MB

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
