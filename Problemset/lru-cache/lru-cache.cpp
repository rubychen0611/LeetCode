
// @Title: LRU 缓存机制 (LRU Cache)
// @Author: rubychen0611
// @Date: 2021-10-09 21:08:13
// @Runtime: 368 ms
// @Memory: 161.2 MB

struct MyListNode {
    int key;
    int value;
    MyListNode* prev;
    MyListNode* next;
    MyListNode(int _key, int _value) {
        key = _key;
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    unordered_map<int, MyListNode*> nodeAddr;
    int listSize;
    int capacity;
    MyListNode* head;
    void addToHead(MyListNode* node) {
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }
    void removeFromList(MyListNode* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
public:
    LRUCache(int capacity) {
        listSize = 0;
        this->capacity = capacity;
        // create dummy node
        head = new MyListNode(-1, -1);
        head -> prev = head;
        head -> next = head;
    }
    
    int get(int key) {
        if(nodeAddr.find(key) != nodeAddr.end()) {
            MyListNode* node = nodeAddr[key];
            if(node != head -> next) {
                removeFromList(node);
                addToHead(node);
            }
            return nodeAddr[key] -> value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(nodeAddr.find(key) != nodeAddr.end()) {
            MyListNode* node = nodeAddr[key];
            node -> value = value;
            if(node != head -> next) {
                removeFromList(node);
                addToHead(node);
            }
            return;
        }
        if(listSize == capacity) {
            // remove last node
            MyListNode* lastNode = head -> prev;
            nodeAddr.erase(lastNode -> key);
            removeFromList(lastNode);
            delete(lastNode);
            listSize --;
        }
        MyListNode* newNode = new MyListNode(key, value);
        addToHead(newNode);
        nodeAddr.insert(pair<int, MyListNode*>(key, newNode));
        listSize ++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
