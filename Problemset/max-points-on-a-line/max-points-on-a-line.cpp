
// @Title: 直线上最多的点数 (Max Points on a Line)
// @Author: rubychen0611
// @Date: 2021-01-22 15:52:40
// @Runtime: 20 ms
// @Memory: 11.3 MB

class Solution {
private:
    long double calculate_k(const vector<int>& p1, const vector<int> & p2)
    {
        return (long double)(p1[1] - p2[1]) / (p1[0] - p2[0]);
    }
public:
    int maxPoints(vector<vector<int>>& points)
    {
        if (points.empty())
            return 0;
        for (const vector<int> & point: points)
        {

        }
        int max = 1;
        for(int i = 0; i < points.size(); i++)
        {
            int cur_max = 1;
            int same = 0;
            unordered_map<long double, int> count_map;
            int count_vertical = 1;
            const vector<int> & p1 = points[i];
            for (int j = i + 1; j < points.size(); j++)
            {
                const vector<int> &p2 = points[j];
                if(p1[0] == p2[0])
                {
                    if (p1[1] == p2[1]) // 重合的点
                    {
                        same ++;
                    }
                    else        // 横坐标相同：斜率不存在
                    {
                        count_vertical += 1;
                        if (count_vertical > cur_max)
                            cur_max = count_vertical;
                    }
                }
                else    // 横纵坐标都不相同：有斜率
                {
                    long double k = calculate_k(p1, p2);
                    //cout << k <<endl;
                    if (count_map.find(k) == count_map.end())
                        count_map[k] = 2;
                    else
                        count_map[k] ++;
                    if(count_map[k] > cur_max)
                        cur_max = count_map[k];
                }
            }
            if (cur_max + same > max)
                max = cur_max + same;
        }
        return max;
    }
};

