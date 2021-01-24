
// @Title: 删除链表的节点 (删除链表的节点 LCOF)
// @Author: rubychen0611
// @Date: 2020-12-27 17:30:20
// @Runtime: 16 ms
// @Memory: 9.5 MB

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
    ListNode* deleteNode(ListNode* head, int val) {
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
                break;
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

