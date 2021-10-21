
// @Title: 省份数量 (省份数量)
// @Author: rubychen0611
// @Date: 2021-10-20 11:33:42
// @Runtime: 28 ms
// @Memory: 13.3 MB

class UFSet {
private:
    vector<int> parent;
public:
    UFSet(int n) {
        parent.resize(n, -1);
    }

    void Union(int x, int y) {
        int root1 = Find(x);
        int root2 = Find(y);
        if(root1 != root2) {
            int size1 = -parent[root1];
            int size2 = -parent[root2];
            if(size1 <= size2) {
                parent[root1] = root2;
            }
            else {
                parent[root2] = root1;
            }
        }
        return;
    }

    int Find(int x) {
        while(parent[x] > 0) {
            x = parent[x];
        }
        return x;
    }

    int CircleNum() {
        int count = 0;
        for(int i = 0; i < parent.size(); i++){
            if(parent[i] < 0) {
                count ++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UFSet ufSet(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j]) {
                    ufSet.Union(i, j);
                }
            }
        }
        return ufSet.CircleNum();
    }
};
