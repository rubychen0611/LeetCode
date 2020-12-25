
// @Title: 奇偶链表 (Odd Even Linked List)
// @Author: rubychen0611
// @Date: 2020-12-25 16:08:19
// @Runtime: 24 ms
// @Memory: 10.8 MB

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
    void addNode(ListNode* &head, ListNode* &tail, ListNode* p)
    {
        if(!head && !tail)
            head = p;
        else
            tail -> next = p;
        tail = p;
        tail -> next = NULL;
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* odd_head = NULL, * even_head = NULL;
        ListNode* odd_tail = NULL, * even_tail = NULL;
        bool odd_flag = true;
        ListNode* p = head;
        while(p)
        {
            if (odd_flag)
            {
                ListNode* tmp = p;
                p = p -> next;
                addNode(odd_head, odd_tail, tmp);
            }
            else
            {
                ListNode* tmp = p;
                p = p -> next;
                addNode(even_head, even_tail, tmp);
            }
            odd_flag = !odd_flag;
        }
        odd_tail -> next = even_head;
        return odd_head;
    }
};

