
// @Title: 合并两个链表 (Merge In Between Linked Lists)
// @Author: rubychen0611
// @Date: 2021-01-03 17:31:51
// @Runtime: 644 ms
// @Memory: 92.6 MB

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
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list2_tail = list2;
        while(list2_tail -> next != NULL)
            list2_tail = list2_tail -> next;

        ListNode* p = list1, *prev = NULL, *pa = NULL, *pb;
        int i = -1;
        while(p)
        {
            i++;
            if(i == a)
            {
                pa = prev;
            }
            if(i == b)
            {
                pb = p -> next;
            }

            prev = p;
            p = p -> next;
        }
        ListNode* head;
        if (pa)
        {
            pa -> next = list2;
            head = list1;
        }
        else
            head = list2;
        if (pb)
        {
            list2_tail -> next = pb;
        }
        return head;
    }
};

