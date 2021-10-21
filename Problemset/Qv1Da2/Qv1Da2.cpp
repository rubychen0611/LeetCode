
// @Title: 展平多级双向链表 (展平多级双向链表)
// @Author: rubychen0611
// @Date: 2021-10-08 22:24:18
// @Runtime: 4 ms
// @Memory: 7.2 MB

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    void dfsFlatten(Node* head, Node* &childTail) {
        Node* p = head, *p_prev = nullptr;
        while(p != nullptr) {
            if (p -> child != nullptr) {
                Node* pChild = p -> child, *pChildTail = nullptr;
                dfsFlatten(pChild, pChildTail);
                p -> child = nullptr;
                Node* tmp = p -> next;
                p -> next = pChild;
                pChild -> prev = p;
                if(tmp != nullptr) {
                    tmp -> prev = pChildTail;
                    pChildTail -> next = tmp;
                }
            }
            p_prev = p;
            p = p -> next;
        }
        childTail = p_prev;
    }
public:
    Node* flatten(Node* head) {
        Node* childTail = nullptr;
        dfsFlatten(head, childTail);
        return head;
    }
};

