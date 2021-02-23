
// @Title: 细分图中的可到达结点 (Reachable Nodes In Subdivided Graph)
// @Author: rubychen0611
// @Date: 2021-02-13 15:04:36
// @Runtime: 1040 ms
// @Memory: 36.5 MB

struct GraphNode
{
    int v;
    int weight;
    GraphNode(int n, int w):v(n), weight(w){}
};
class Solution {
private:
    int findMin(vector<int>& dist, vector<bool> &used)
    {
        int min = INT_MAX, min_i = -1;
        for(int i = 1; i < dist.size(); i++)
        {
            if(!used[i])
            {
                if(dist[i] < min)
                {
                    min = dist[i];
                    min_i = i;
                }
            }
        }
        return min_i;
    }
    int getWeight(vector<vector<GraphNode>> &graph, int u, int v)
    {
        for(GraphNode neighbor: graph[u])
        {
            if(neighbor.v == v)
                return neighbor.weight;
        }
        return -1;
    }
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // 建图
        vector<vector<GraphNode>> graph(n, vector<GraphNode>());
        for(vector<int>& edge: edges)
        {
            graph[edge[0]].push_back(GraphNode(edge[1], edge[2] + 1));
            graph[edge[1]].push_back(GraphNode(edge[0], edge[2] + 1));
        }

        vector<int> dist(n, maxMoves+ 1);    // 初始化最短距离
        dist[0] = 0;
        for(GraphNode neighbor: graph[0])
        {
            dist[neighbor.v] = neighbor.weight;     // 初始化
        }
        vector<bool> used(n, false);
        used[0] = true;
        int count = 1;  // 已找到最短路径的顶点个数
        while(count < n)
        {
            int p = findMin(dist, used);
            used[p] = true;
            count ++;
            for(int i = 1; i < n; i++)  // 更新
            {
                if(!used[i])
                {
                    int w = getWeight(graph, i, p);
                    if(w != -1) // i 和p 之间有边
                    {
                        dist[i] = min(dist[i], dist[p] + w);
                    }
                }
            }
        }
        int ans = 0;
        for(vector<int> &edge: edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            int d = 0;
            if(dist[u] <= maxMoves)
                d += maxMoves - dist[u];
            if(dist[v] <= maxMoves)
                d += maxMoves - dist[v];
            ans += min(d, w);
        }
        for(int i = 0; i < n; i++)
        {
            if(dist[i] <= maxMoves)
                ans ++;
        }
        return ans;

    }
};

