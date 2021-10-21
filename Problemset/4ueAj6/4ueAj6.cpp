
// @Title: 排序的循环链表 (排序的循环链表)
// @Author: rubychen0611
// @Date: 2021-10-08 22:51:33
// @Runtime: 4 ms
// @Memory: 8 MB

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head -> next = head;
            return head;
        }
        Node* p_prev = head, *p = head -> next;
        Node* newNode = new Node(insertVal);
        while(p != head) {
            // 1. 插在中间
            if( (p_prev -> val <= insertVal && insertVal <= p -> val)
            // 2. 插在两头之间
            || ((p_prev -> val > p -> val)
                && (insertVal >= p_prev -> val || insertVal <= p -> val))) {
                p_prev -> next = newNode;
                newNode -> next = p;
                break;
            }
            p_prev = p;
            p = p -> next;
        }
        if (p == head) {
            p_prev -> next = newNode;
            newNode -> next = p;
        }
        return head;
    }
};

