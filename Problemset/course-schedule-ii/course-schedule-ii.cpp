
// @Title: 课程表 II (Course Schedule II)
// @Author: rubychen0611
// @Date: 2021-02-12 20:21:45
// @Runtime: 32 ms
// @Memory: 13.7 MB

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());   // 图
        vector<int> indegree(numCourses, 0); // 入度
        for(vector<int> pair: prerequisites)
        {
            graph[pair[1]].push_back(pair[0]);
            indegree[pair[0]] ++;
        }
        queue<int> Q; // 队列保存入度为0的结点
        vector<int> ans;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                Q.push(i);
        }
        while(!Q.empty())
        {
            int p = Q.front();
            Q.pop();
            ans.push_back(p);
            for(int neighbor: graph[p])
            {
                indegree[neighbor] --;
                if(indegree[neighbor] == 0)
                    Q.push(neighbor);
            }
        }
        if(ans.size() != numCourses)
            return vector<int>();
        return ans;
    }
};
