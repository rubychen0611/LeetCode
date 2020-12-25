
// @Title: 找到所有数组中消失的数字 (Find All Numbers Disappeared in an Array)
// @Author: rubychen0611
// @Date: 2020-12-22 15:46:12
// @Runtime: 100 ms
// @Memory: 32.8 MB

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1), ans;
        for (int x : nums)
            count[x] ++;
        for (int i = 1; i <= n; i++)
        {
            if(count[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};

