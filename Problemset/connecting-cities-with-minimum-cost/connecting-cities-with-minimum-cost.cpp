
// @Title: 最低成本联通所有城市 (Connecting Cities With Minimum Cost)
// @Author: rubychen0611
// @Date: 2021-02-13 13:19:03
// @Runtime: 216 ms
// @Memory: 51.4 MB

class UFSet
{
private:
    int n;
    vector<int> parent;
public:
    UFSet(int n)
    {
        this-> n = n;
        parent.resize(n, -1);
    }
    int find(int i)  // 路径压缩
    {
        // 搜索根root
        int root = i;
        while(parent[root] >= 0)
            root = parent[root];
        while(i != root)
        {
            int tmp = parent[i];
            parent[i] = root;
            i = tmp;
        }
        return root;
    }
    void set_union(int i, int j)
    {
        int root1 = find(i), root2 = find(j);
        if(root1 != root2)
        {
            int tmp = parent[root1] + parent[root2];
            if(parent[root1] < parent[root2])
            {
                parent[root1] = root2;
                parent[root2] = tmp;
            }
            else
            {
                parent[root2] = root1;
                parent[root1] = tmp;
            }
        }
    }
    void union_root(int root1, int root2)
    {
        if(root1 != root2)
        {
            int tmp = parent[root1] + parent[root2];
            if(parent[root1] < parent[root2])
            {
                parent[root1] = root2;
                parent[root2] = tmp;
            }
            else
            {
                parent[root2] = root1;
                parent[root1] = tmp;
            }
        }
    }
};
struct Edge // 用于Kruskal算法
{
    int u, v;
    int weight;
    Edge(int s, int e, int w):u(s), v(e), weight(w){}
    bool operator > (const Edge& e1) const
    {
        return weight > e1.weight;
    }
};

struct EdgeNode // 用于Prim算法的图
{
    int v;
    int weight;
    EdgeNode(int n, int w):v(n), weight(w){}
    bool operator > (const EdgeNode& e1) const
    {
        return weight > e1.weight;
    }
};
class Solution {
private:
    int Kruskal(int N, vector<vector<int>>& connections)    // Kruskal算法
    {
        priority_queue<Edge,vector<Edge>, greater<Edge>> min_heap;
        for(vector<int> e: connections)
        {
            min_heap.push(Edge(e[0] - 1, e[1] - 1, e[2]));
        }
        UFSet ufset(N);    // 并查集
        int count = 0;
        int ans = 0;
        while(count < N && !min_heap.empty())   // 取 N-1条边
        {
            Edge e = min_heap.top();
            min_heap.pop();
            int r1 = ufset.find(e.u), r2 = ufset.find(e.v);
            if(r1 != r2)
            {
                ufset.union_root(r1, r2);
                ans += e.weight;
                count ++;
            }
        }
        if(count != N-1)
            return -1;
        return ans;
    }
    int Prim(int N, vector<vector<int>>& connections)    // prim算法
    {
        vector<vector<EdgeNode>> graph(N, vector<EdgeNode>());
        // 建图
        for(vector<int> e: connections)
        {
            graph[e[0] - 1].push_back(EdgeNode(e[1] - 1, e[2]));
            graph[e[1] - 1].push_back(EdgeNode(e[0] - 1, e[2]));
        }
        vector<bool> used(N, false); // 定点集合
        priority_queue<EdgeNode,vector<EdgeNode>, greater<EdgeNode>> min_heap;
        int p = 0;
        int count = 1;
        int ans = 0;
        do
        {
            used[p] = true;
            for(EdgeNode neighbor: graph[p])
            {
                if(used[neighbor.v] == false)
                {
                    min_heap.push(neighbor);
                }
            }
            while(!min_heap.empty() && count < N)
            {
                EdgeNode e = min_heap.top();
                min_heap.pop();
                if(!used[e.v])
                {
                    ans += e.weight;
                    used[e.v] = true;
                    p = e.v;
                    count ++;
                    break;
                }
            }
        }while(count < N);
        if(count < N)
            return -1;
        return ans;
    }
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        if (connections.size() < N-1)   // 不连通，不可能有最小生成树
            return -1;
        // return Kruskal(N, connections);
        return Prim(N, connections);
    }
};

