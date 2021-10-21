
// @Title: 数组中和为 0 的三个数 (数组中和为 0 的三个数)
// @Author: rubychen0611
// @Date: 2021-09-03 15:34:49
// @Runtime: 27 ms
// @Memory: 42.7 MB

class Solution {
 private List<List<Integer>> twoSum(int[]nums, int startIdx, int sum)
    {
        int p = startIdx, q = nums.length - 1;
        List<List<Integer>> result = new ArrayList<List<Integer>> ();
        while(p < q)
        {
            if(p > startIdx && nums[p] == nums[p-1])
            {
                p ++;
            }
            else if (nums[p] + nums[q] == sum)
            {
                result.add(Arrays.asList(nums[p], nums[q]));
                p++;
                q--;
            }
            else if (nums[p] + nums[q] < sum)
                p++;
            else
                q--;
        }
        return result;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>> ();
        if(nums.length < 3)
            return result;
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 2; i ++)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            List<List<Integer>> twoSumResult = twoSum(nums, i+1, -nums[i]);
            for(List<Integer> pair: twoSumResult)
            {
                result.add(Arrays.asList(nums[i], pair.get(0), pair.get(1)));
            }
        }
        return result;

    }
}
