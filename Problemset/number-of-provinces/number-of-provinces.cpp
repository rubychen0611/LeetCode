
// @Title: 省份数量 (Number of Provinces)
// @Author: rubychen0611
// @Date: 2021-02-06 14:00:53
// @Runtime: 32 ms
// @Memory: 13.5 MB

class Solution {
private:
    void search(vector<vector<int>>& isConnected, int i)
    {
        isConnected[i][i] = 0;
        for(int j = 0; j < isConnected.size(); j++)
        {
            //cout << i << " " << j << endl;
            if(isConnected[i][j] == 1)
            {
                isConnected[i][j] = 0;
                isConnected[j][i] = 0;
                search(isConnected, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(isConnected[i][i])
            {
                search(isConnected, i);
                count++;
            }
        }
        return count;
    }
};

