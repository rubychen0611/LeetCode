
// @Title: 分隔链表 (Partition List)
// @Author: rubychen0611
// @Date: 2021-01-03 16:59:53
// @Runtime: 4 ms
// @Memory: 7.2 MB

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = NULL, *p2 = head, *p2_prev = NULL, *tmp;
        while(p2)
        {
            if (p2 -> val < x)
            {
                tmp = p2;
                p2 = p2 -> next;
                if (p2_prev)
                    p2_prev -> next = p2;
                if (p1 == NULL)
                {
                    p1 = tmp;
                    if(p1 != head)
                    {
                        p1 -> next = head;
                        head = p1;
                    }
                } else
                {
                    if(p1 -> next != tmp) {
                        tmp->next = p1->next;
                        p1->next = tmp;
                    }
                    p1 = tmp;
                }
            }
            else
            {
                p2_prev = p2;
                p2 = p2->next;
            }
        }
        return head;
    }
};

