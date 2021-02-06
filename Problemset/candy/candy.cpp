
// @Title: 分发糖果 (Candy)
// @Author: rubychen0611
// @Date: 2021-01-24 19:17:36
// @Runtime: 52 ms
// @Memory: 19.8 MB

struct Child
{
    int rating;
    int pos;
    Child(int r, int p): rating(r), pos(p){}
    bool operator > (const Child & c) const
    {
        return this->rating > c.rating;
    }
};

class Solution {
private:
    int max (int a, int b)
    {
        return a > b? a :b;
    }
public:
    int candy(vector<int>& ratings)
    {
         int n = ratings.size();
         vector<int> candy(n);
         priority_queue<Child, vector<Child>,greater<Child>> children;
         for(int i = 0; i < n; i++)
         {
             children.push(Child(ratings[i], i));
         }
         while(!children.empty())
         {
             Child c = children.top();
             int p = c.pos;
             int right = 0, left = 0;
             if (p > 0 && candy[p-1] > 0 && ratings[p-1] < ratings[p])
                 left = candy[p-1];
             if (p < n-1 && candy[p+1] > 0 && ratings[p+1] < ratings[p])
                 right = candy[p+1];
             candy[p] = max(left, right) + 1;
             children.pop();
         }
         int ans = 0;
         for(int i = 0; i < n; i++)
         {
             //cout << candy[i]<< endl;
             ans += candy[i];
         }
         return ans;
    }
};

