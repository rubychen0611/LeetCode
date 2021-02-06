
// @Title: 等差数列划分 (Arithmetic Slices)
// @Author: rubychen0611
// @Date: 2021-01-25 21:32:55
// @Runtime: 0 ms
// @Memory: 7 MB

class Solution {
private:
    int cal_C_m_2(int m) // 组合数 C[m,2]
    {
        return m * (m-1) / 2;
    }
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty())
            return 0;
        if (A.size() == 1)
            return 0;
        int sum = 0, cur_count = 1, cur_diff = A[1]-A[0];
        for(int i = 1; i < A.size()-1; i++)
        {
            int diff = A[i+1] - A[i];
            if(diff == cur_diff)
            {
                cur_count ++;
            }
            else{
                if (cur_count >= 2)
                    sum += cal_C_m_2(cur_count);
                cur_count = 1;
                cur_diff = diff;
            }
        }
        if (cur_count >= 2)
            sum += cal_C_m_2(cur_count);
        return sum;
    }
};

