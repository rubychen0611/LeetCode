
// @Title: 对链表进行插入排序 (Insertion Sort List)
// @Author: rubychen0611
// @Date: 2021-01-03 19:25:16
// @Runtime: 48 ms
// @Memory: 9.9 MB

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;

        ListNode* p = head->next, *q, *q_prev, *tmp;
        head -> next = NULL;
        while(p)
        {
            tmp = p;
            p = p -> next;
            q = head;
            q_prev = nullptr;
            while(q)
            {
                if (q -> val > tmp -> val)
                {
                    if (q_prev == NULL)
                    {
                        tmp -> next = head;
                        head = tmp;
                    }
                    else
                    {
                        tmp -> next = q_prev -> next;
                        q_prev -> next = tmp;
                    }
                    break;
                }
                q_prev = q;
                q = q -> next;
            }
            if (q == NULL)
            {
                q_prev -> next = tmp;
                tmp -> next = NULL;
            }
        }
        return head;
    }
};

