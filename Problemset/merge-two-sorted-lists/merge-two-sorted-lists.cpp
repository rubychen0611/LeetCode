
// @Title: 合并两个有序链表 (Merge Two Sorted Lists)
// @Author: rubychen0611
// @Date: 2021-02-16 20:16:28
// @Runtime: 8 ms
// @Memory: 14.4 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* head, *tail; 
    void addNode(ListNode* p)
    {
        if(head == nullptr)
            head = p;
        else
            tail -> next = p;
        tail = p;
        p -> next = nullptr;
    } 
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return nullptr;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* p1 = l1, *p2 = l2;
        head = tail = nullptr;
        while(p1 != nullptr && p2 != nullptr)
        {
            if(p1 -> val <= p2 -> val)
            {
                ListNode* tmp = p1;
                p1 = p1 -> next;
                addNode(tmp);
                
            }
            else 
            {
                ListNode* tmp = p2;
                p2 = p2 -> next;
                addNode(tmp);
            }
        }
        if(!p1)
            tail -> next = p2;
        else if (!p2)
            tail -> next = p1;
        return head;
    }
};
