
// @Title: 和为 k 的子数组 (和为 k 的子数组)
// @Author: rubychen0611
// @Date: 2021-09-05 23:27:34
// @Runtime: 23 ms
// @Memory: 41.8 MB

class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer>  sumToCount = new HashMap<Integer, Integer>();
        sumToCount.put(0, 1);
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.length; i++)
        {
            sum += nums[i];
            ans += sumToCount.getOrDefault(sum - k, 0);
            sumToCount.put(sum, sumToCount.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}
