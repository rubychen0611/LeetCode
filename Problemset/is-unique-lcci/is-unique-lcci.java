
// @Title: 判定字符是否唯一 (Is Unique LCCI)
// @Author: rubychen0611
// @Date: 2021-08-30 00:20:49
// @Runtime: 0 ms
// @Memory: 36.1 MB

class Solution {

    public boolean isUnique(String astr) {
        int flag = 0;
        for(int i = 0; i < astr.length(); i++)
        {
            char ch = astr.charAt(i);
            int p = 1 << (ch - 'a');
            if ((flag & p) != 0)
                return false;
            flag |= p; 
        }
        return true;
    }
}
