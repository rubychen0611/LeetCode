
// @Title: 区域和检索 - 数组不可变 (Range Sum Query - Immutable)
// @Author: rubychen0611
// @Date: 2021-02-12 15:07:58
// @Runtime: 24 ms
// @Memory: 16.5 MB

class NumArray {
private:
    vector<int> sumArray;
public:
    NumArray(vector<int>& nums) {
        sumArray.resize(nums.size());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sumArray[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return sumArray[j];
        return sumArray[j] - sumArray[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
