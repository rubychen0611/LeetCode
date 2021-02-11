
// @Title: 冗余连接 (Redundant Connection)
// @Author: rubychen0611
// @Date: 2021-02-09 10:39:17
// @Runtime: 4 ms
// @Memory: 8 MB


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
    int find(int i)
    {
        while(parent[i] >= 0)
            i = parent[i];
        return i;
    }
    int collapsing_find(int i)  // 路径压缩
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
//    void set_union(int i, int j)
//    {
//        int root1 = find(i), root2 = find(j);
//        if(root1 != root2)
//        {
//            int tmp = parent[root1] + parent[root2];
//            if(parent[root1] < parent[root2])
//            {
//                parent[root1] = root2;
//                parent[root2] = tmp;
//            }
//            else
//            {
//                parent[root2] = root1;
//                parent[root1] = tmp;
//            }
//        }
//    }
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
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UFSet ufset(n);
        for(const vector<int> &edge: edges)
        {
            int r1 = ufset.collapsing_find(edge[0]-1), r2 = ufset.collapsing_find(edge[1]-1);
            if(r1 == r2)
                return edge;
            else
                ufset.union_root(r1, r2);
        }
        return vector<int>();
    }
};

