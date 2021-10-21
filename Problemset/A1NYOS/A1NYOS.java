
// @Title: 0 和 1 个数相同的子数组 (0 和 1 个数相同的子数组)
// @Author: rubychen0611
// @Date: 2021-10-01 17:25:07
// @Runtime: 23 ms
// @Memory: 48.1 MB

class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> sumToIndex = new HashMap<>();
        int sum = 0;
        int maxLength = 0;
        sumToIndex.put(0, -1);
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] == 0)
                nums[i] = -1;
            sum += nums[i];
            if (sumToIndex.containsKey(sum)) {
                maxLength = Math.max(maxLength, i - sumToIndex.get(sum));
            } else {
                sumToIndex.put(sum, i);
            }
        }
        return maxLength;
    }
}

