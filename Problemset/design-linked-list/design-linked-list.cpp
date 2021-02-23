
// @Title: 设计链表 (Design Linked List)
// @Author: rubychen0611
// @Date: 2021-02-16 18:14:33
// @Runtime: 40 ms
// @Memory: 19.3 MB

struct Node
{
    int val;
    Node* prev, *next;
    Node(){val = -1; prev = nullptr; next = nullptr;}
    Node(int v){val = v; next = nullptr;}
};

class MyLinkedList {
private:
    Node* dummy;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new Node();
        dummy -> prev = dummy;
        dummy -> next = dummy;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* p = dummy -> next;
        for(int i = 0; i < index; i++)
        {
            p = p -> next;
            if(p == dummy)
                return -1;
        }
        return p -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node -> next = dummy -> next;
        node -> prev = dummy;
        dummy -> next -> prev = node;
        dummy -> next = node;   
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        node -> prev = dummy -> prev;
        node -> next = dummy;
        dummy -> prev -> next = node;
        dummy -> prev = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index <= 0)
            addAtHead(val);
        else
        {
            int count = 0;
            Node* p = dummy -> next;
            while(p != dummy && count < index)
            {
                p = p -> next;
                count ++;
            }
            if(p == dummy)
            {
                if(count == index)  // 此时count==长度
                {
                    addAtTail(val);
                    return;
                }    
                else return;
            }

            Node* node = new Node(val);
            node -> next = p;
            node -> prev = p -> prev;
            p -> prev -> next = node;
            p -> prev = node;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int count = 0;
        Node* p = dummy -> next;
        while(p != dummy && count < index)
        {
            p = p -> next;
            count ++;
        }
        if(p == dummy)
            return;
        p -> prev -> next = p ->next;
        p -> next -> prev = p ->prev;
        delete p;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
