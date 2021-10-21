
// @Title: 将字符串翻转到单调递增 (Flip String to Monotone Increasing)
// @Author: rubychen0611
// @Date: 2021-10-17 20:53:12
// @Runtime: 40 ms
// @Memory: 15.2 MB

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
