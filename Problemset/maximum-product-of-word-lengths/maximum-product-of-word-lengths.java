
// @Title: 最大单词长度乘积 (Maximum Product of Word Lengths)
// @Author: rubychen0611
// @Date: 2021-08-29 21:31:08
// @Runtime: 6 ms
// @Memory: 38.4 MB

class Solution {
    public int maxProduct(String[] words) {
        int n = words.length;
        int[] flags = new int[n];
        for(int i = 0; i < n; i++)
        {
            flags[i] = calculateFlag(words[i]);
        }
        int max_product = 0;
        for(int i = 0 ; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if((flags[i] & flags[j]) == 0)
                {
                    int product = words[i].length() * words[j].length();
                    if (product > max_product)
                        max_product = product;
                }
            }
        }
        return max_product;
    }
    private int calculateFlag(String word)
    {
        int flag = 0;
        for(int i = 0; i < word.length(); i++)
        {
            char ch = word.charAt(i);
            flag |= (1 << (ch - 'a')); 
        }
        return flag;
    }
}
