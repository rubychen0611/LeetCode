
// @Title: 最近的请求次数 (Number of Recent Calls)
// @Author: rubychen0611
// @Date: 2021-10-12 11:52:07
// @Runtime: 124 ms
// @Memory: 56.1 MB

class RecentCounter {
private:
    queue<int> Q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        while(!Q.empty() && Q.front() < t - 3000) {
            Q.pop();
        }
        Q.push(t);
        return Q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
