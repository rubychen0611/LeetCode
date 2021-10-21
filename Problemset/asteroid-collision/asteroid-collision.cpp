
// @Title: 行星碰撞 (Asteroid Collision)
// @Author: rubychen0611
// @Date: 2021-10-11 11:31:58
// @Runtime: 8 ms
// @Memory: 17.5 MB

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = asteroids.size() - 1; i >= 0; i--) {
            int asteroid = asteroids[i];
            bool boom = false;
            while(!st.empty() && st.top() < 0  && asteroid > 0) {
                if(abs(st.top()) == abs(asteroid)) {
                    st.pop();
                    boom = true;
                    break;
                }
                else if(abs(st.top()) < abs(asteroid)) {
                    st.pop();
                }
                else {
                    boom = true;
                    break;
                }
            }
            if(boom == false) {
                st.push(asteroid);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
