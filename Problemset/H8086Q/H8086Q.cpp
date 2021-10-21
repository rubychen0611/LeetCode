
// @Title: 最近请求次数 (最近请求次数)
// @Author: rubychen0611
// @Date: 2021-10-12 11:51:46
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
