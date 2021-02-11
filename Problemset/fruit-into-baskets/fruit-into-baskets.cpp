
// @Title: 水果成篮 (Fruit Into Baskets)
// @Author: rubychen0611
// @Date: 2021-02-11 13:08:20
// @Runtime: 112 ms
// @Memory: 57.9 MB

struct Info
{
    int type;
    int num;
    Info(int t, int n): type(t), num(n){}
};
class Solution {
private:
    bool ifInQueue(int type, queue<Info> &Q)
    {
        if(Q.empty())
            return false;
        if(Q.size() == 1)
            return Q.front().type == type; 
        return Q.front().type == type || Q.back().type == type;
    }
public:
    int totalFruit(vector<int>& tree) {
        int type = tree[0], count = 1;
        vector<Info> tree_info;
        for(int i = 1; i < tree.size(); i++)
        {
            if(tree[i] == type)
                count ++;
            else
            {
                tree_info.push_back(Info(type, count));
                count = 1;
                type = tree[i];
            }
        }
        tree_info.push_back(Info(type, count));
        if(tree_info.size() == 1)
            return tree_info[0].num;
        int type1 = tree_info[0].type, type2 = tree_info[1].type;
        int cur =  tree_info[0].num + tree_info[1].num, max = cur;
        for(int i = 2; i < tree_info.size(); i++)
        {
            if(tree_info[i].type == type1 || tree_info[i].type == type2)
                cur += tree_info[i].num;
            else{
                type1 = tree_info[i-1].type;
                type2 = tree_info[i].type;
                cur = tree_info[i-1].num + tree_info[i].num;
            }
            if(cur > max)
                max = cur;
        }
        return max;
    }
};
