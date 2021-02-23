
// @Title: 和为K的子数组 (Subarray Sum Equals K)
// @Author: rubychen0611
// @Date: 2021-02-12 16:05:54
// @Runtime: 116 ms
// @Memory: 40.7 MB

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash_map;
        int sum = 0;
        hash_map[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            ans += hash_map[sum - k];
            hash_map[sum] ++;
        }
        return ans;
    }
};
