
// @Title: 相交链表 (Intersection of Two Linked Lists)
// @Author: rubychen0611
// @Date: 2020-12-25 14:38:58
// @Runtime: 68 ms
// @Memory: 14.6 MB

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* p = headA, *q = headB;
        while(p != q)
        {
            if (p == NULL)
                p = headB;
            else
                p = p -> next;
            if (q == NULL)
                q = headA;
            else
                q = q -> next;
        }
        return p;
    }

};

