
// @Title: 设计链表 (Design Linked List)
// @Author: rubychen0611
// @Date: 2020-12-25 11:19:03
// @Runtime: 68 ms
// @Memory: 19.8 MB

struct Node
{
    int val;
    Node* prev, *next;
    Node(int x): val(x), prev(NULL), next(NULL) {}
};
class MyLinkedList {
private:
    Node* dummy;
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        dummy = new Node(-1);
        dummy->prev = dummy;    // dummy->prev指向表尾
        dummy->next = dummy;    // dummy->next指向表头
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        Node* p = dummy -> next;
        for(int i = 0; i < index; i ++)
        {
            p = p -> next;
            if(p == dummy)
                return -1;
        }
        return p -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node* n = new Node(val);
        n -> next = dummy -> next;
        n -> prev = dummy;
        dummy -> next -> prev = n;
        dummy -> next = n;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node* n = new Node(val);
        n -> next = dummy;
        n -> prev = dummy -> prev;
        dummy -> prev -> next = n;
        dummy -> prev = n;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index <= 0)
        {
            addAtHead(val);
            return;
        }
        Node* p = dummy -> next;
        for(int i = 0; i < index; i ++)
        {
            p = p -> next;
            if(p == dummy)
            {
                if (i + 1 == index) {
                    addAtTail(val);
                    return;
                }
                else return;
            }
        }
        Node* n = new Node(val);
        n -> next = p;
        n -> prev = p -> prev;
        p -> prev -> next = n;
        p -> prev = n;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        Node* p = dummy -> next;
        for(int i = 0; i < index; i ++)
        {
            p = p -> next;
            if(p == dummy)
                return;
        }
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
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

