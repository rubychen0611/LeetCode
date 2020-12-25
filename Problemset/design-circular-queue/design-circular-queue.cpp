
// @Title: 设计循环队列 (Design Circular Queue)
// @Author: rubychen0611
// @Date: 2020-12-24 16:27:34
// @Runtime: 36 ms
// @Memory: 16.9 MB

class MyCircularQueue {
private:
    vector<int> Q;
    int head, tail;
    int size;
public:
    MyCircularQueue(int k) {
        size = k + 1;
        Q.resize(size);
        head = 0;
        tail = 0;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        Q[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return Q[head];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return Q[(tail - 1 + size) % size];
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        return (tail + 1) % size == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

