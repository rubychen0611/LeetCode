
// @Title: 移除链表元素 (Remove Linked List Elements)
// @Author: rubychen0611
// @Date: 2020-12-27 16:36:38
// @Runtime: 56 ms
// @Memory: 15.3 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        ListNode* prev = head, *p = head;
        while(p != NULL)
        {
            if (p -> val == val)
            {
                ListNode* tmp = p;
                p = p -> next;
                if(tmp == head)
                {
                    head = tmp -> next;
                }
                else
                {
                    prev -> next = tmp -> next;
                }
                delete tmp;
            }
            else
            {
                prev = p;
                p = p -> next;
            }
        }
        return head;
    }
};

