
// @Title: 设计前中后队列 (Design Front Middle Back Queue)
// @Author: rubychen0611
// @Date: 2020-12-24 19:19:05
// @Runtime: 72 ms
// @Memory: 20.3 MB

class FrontMiddleBackQueue {
private:
    list<int> Q;
    list<int>::iterator mid;
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        if(Q.empty())
        {
            Q.push_front(val);
            mid = Q.begin();
        }
        else
        {
            if (Q.size() % 2 == 1)      // 奇数
            {
                Q.push_front(val);
                mid --;
            }
            else    // 偶数
            {
                Q.push_front(val);
            }
        }
    }
    
    void pushMiddle(int val)
    {
        if (Q.empty()) {
            pushFront(val);
            return;
        }
        if(Q.size() % 2 == 1)
        {
            mid = Q.insert(mid, val);
        }
        else
        {
            mid ++;
            mid = Q.insert(mid, val);
        }
    }
    
    void pushBack(int val) {
        if(Q.empty())
        {
            Q.push_back(val);
            mid = Q.begin();
        }
        else
        {
            if (Q.size() % 2 == 1)      // 奇数
            {
                Q.push_back(val);
            }
            else    // 偶数
            {
                Q.push_back(val);
                mid ++;
            }
        }
    }
    
    int popFront() {
        if (Q.empty())
            return -1;
        if (Q.size() % 2 == 1)
        {
            int x = Q.front();
            Q.pop_front();
            return x;
        }
        else
        {
            int x = Q.front();
            mid++;
            Q.pop_front();
            return x;
        }
    }
    
    int popMiddle() {
        if (Q.empty())
            return -1;
        list<int>::iterator it = mid;
        if (Q.size() % 2 == 1)
            mid --;
        else
            mid ++;
        int x = *it;
        Q.erase(it);
        return x;
    }
    
    int popBack() {
        if (Q.empty())
            return -1;
        if (Q.size() % 2 == 1)
        {
            int x = Q.back();
            mid--;
            Q.pop_back();
            return x;
        }
        else
        {
            int x = Q.back();
            Q.pop_back();
            return x;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

