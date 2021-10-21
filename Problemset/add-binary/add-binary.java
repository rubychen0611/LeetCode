
// @Title: 二进制求和 (Add Binary)
// @Author: rubychen0611
// @Date: 2021-08-29 20:35:52
// @Runtime: 2 ms
// @Memory: 38.3 MB

class Solution {
    public String addBinary(String a, String b) {
         if (a == "0")
            return b;
        if (b == "0")
            return a;
        int pa = a.length() - 1, pb = b.length() - 1;
        StringBuilder result = new StringBuilder();
        int c = 0;  // 借位
        while(pa >= 0 || pb >= 0)
        {
            int num_a = 0, num_b = 0;
            if (pa >= 0)
                num_a = a.charAt(pa--) - '0';
            if (pb >= 0)
                num_b = b.charAt(pb--) - '0';
            int sum = num_a + num_b + c;
            result.append(sum % 2);
            c = sum > 1 ? 1 : 0;
        }
        if (c == 1)
            result.append(1);
        return result.reverse().toString();
    }
}
