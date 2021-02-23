
// @Title: 判断二分图 (Is Graph Bipartite?)
// @Author: rubychen0611
// @Date: 2021-02-12 19:53:06
// @Runtime: 28 ms
// @Memory: 12.9 MB

class Solution {
private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& color, int cur)
    {
        int c;
        if(color[cur] == 1)
            c = 2;
        else c = 1;
        for(int neighbor: graph[cur])
        {
            if(color[neighbor] == 0) // 未染色
            {
                color[neighbor] = c;
                if (!dfs(graph, color, neighbor))
                    return false;
            }
            else if(color[neighbor] == color[cur])
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(color[i] == 0)
            {
                color[i] = 1;
                if(!dfs(graph, color, i))
                    return false;
            }
        }
        return true;
    }
};
