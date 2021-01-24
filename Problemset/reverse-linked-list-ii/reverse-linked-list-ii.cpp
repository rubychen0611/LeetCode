
// @Title: 反转链表 II (Reverse Linked List II)
// @Author: rubychen0611
// @Date: 2020-12-28 11:31:59
// @Runtime: 4 ms
// @Memory: 6.9 MB

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode* p = head, *prev, *t1= NULL, *h2 = NULL, *t2=NULL, *tmp;
        int count = 0;
        while(p)
        {
            count ++;
            if (count < m)
            {
                prev = p;
                p = p->next;
            }
            else if (count == m)
            {
                tmp = p;
                p = p -> next;
                if (count > 1)
                    t1 = prev;
                h2 = tmp;
                t2 = tmp;
                tmp -> next = NULL;
            }
            else if (count > m && count < n)
            {
                tmp = p;
                p = p -> next;
                tmp -> next = h2;
                h2 = tmp;
            }
            else if (count == n)
            {
                tmp = p;
                p = p -> next;
                tmp -> next = h2;
                h2 = tmp;
                if (t1 != NULL)
                    t1 -> next = h2;
                else head = h2;
                t2 -> next = p;
                break;
            }
        }
        return head;
    }
};

