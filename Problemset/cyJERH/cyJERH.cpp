
// @Title: 翻转字符 (翻转字符)
// @Author: rubychen0611
// @Date: 2021-10-17 20:47:04
// @Runtime: 12 ms
// @Memory: 7.6 MB

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> oneCount(n, 0);
        if(s[0] == '1') {
            oneCount[0] = 1;
        }
        for(int i = 1; i < n; i ++) {
            oneCount[i] = oneCount[i-1];
            if(s[i] == '1') {
                oneCount[i] ++;
            }
        }
        int minFlipsNum = min(n - oneCount[n - 1], oneCount[n-1]); // 全变成1或0
        int leftOneNum, rightZeroNum;
        for(int i = 0; i < n; i++) {
            leftOneNum = oneCount[i];
            rightZeroNum = n - 1 - i - (oneCount[n-1] - oneCount[i]);
            minFlipsNum = min(minFlipsNum, leftOneNum + rightZeroNum);
        }
        return minFlipsNum;
    }
};
