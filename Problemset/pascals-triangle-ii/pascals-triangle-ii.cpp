
// @Title: 杨辉三角 II (Pascal's Triangle II)
// @Author: rubychen0611
// @Date: 2021-02-17 23:57:55
// @Runtime: 4 ms
// @Memory: 6.2 MB

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        for(int i = 1; i <= rowIndex + 1; i++)
        {
            int last = 1;
            for(int j = 1; j < i - 1; j++)
            {
                int tmp = ans[j];
                ans[j] = last + ans[j];
                last = tmp;
            }
        }
        return ans;
    }
};
