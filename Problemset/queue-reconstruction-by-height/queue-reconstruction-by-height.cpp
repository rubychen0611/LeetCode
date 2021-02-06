
// @Title: 根据身高重建队列 (Queue Reconstruction by Height)
// @Author: rubychen0611
// @Date: 2021-01-25 14:45:00
// @Runtime: 148 ms
// @Memory: 23.8 MB

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        int n = people.size();
        if (n == 1)
            return people;
        vector<vector<int>> queue(n, vector<int>(2, -1));
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) -> bool{
            return a[0] < b[0];
        });
        for (vector<int>person: people)
        {
            int pos = 0;
            for(int i = 0; i < person[1]+1; i++)
            {
                while(!(queue[pos][0] == -1 || queue[pos][0] == person[0]))
                    pos++;
                pos++;
            }
            queue[pos-1] = person;
        }
        return queue;

    }
};

