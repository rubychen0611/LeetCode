
// @Title: 复制带随机指针的链表 (Copy List with Random Pointer)
// @Author: rubychen0611
// @Date: 2021-02-17 01:15:23
// @Runtime: 12 ms
// @Memory: 11 MB

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head_copy = nullptr, *tail_copy = nullptr;
        Node* p = head;
        unordered_map<Node *, Node *> copy_map;
        while(p)
        {
            Node* node = new Node(p -> val);
            if(head_copy == nullptr)
                head_copy = node;
            else
                tail_copy -> next = node;
            node -> next = nullptr;
            tail_copy = node;
            copy_map[p] = node;
            p = p -> next;
        }
        p = head;
        Node* p_copy = head_copy;
        while(p)
        {
            p_copy->random = copy_map[p->random];
            p = p -> next;
            p_copy = p_copy -> next;
        }
        return head_copy;
    }
};
