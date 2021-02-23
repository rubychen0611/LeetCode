
// @Title: 从始点到终点的所有路径 (All Paths from Source Lead to Destination)
// @Author: rubychen0611
// @Date: 2021-02-12 20:43:20
// @Runtime: 96 ms
// @Memory: 32.1 MB

class Solution {
private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& vis, int cur, int dst)
    {
        vis[cur] = 1;   // 正在访问
        if(graph[cur].empty())  // 没有出边的结点
        {
            if(dst != cur)
                return false;
        }
        for(int neighbor: graph[cur])
        {
            if(vis[neighbor] == 1)  // 祖先节点 有环路
                return false;
            else if(vis[neighbor] == 2) // 访问过，可到达目标
                continue;
            if(!dfs(graph, vis, neighbor, dst)) //未访问过
                return false;
        }
        vis[cur] = 2;   // 访问结束
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> vis(n, 0);
        for(vector<int> edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        return dfs(graph, vis, source, destination);
    }
};
