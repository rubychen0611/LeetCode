
// @Title: 两个链表的第一个公共节点 (两个链表的第一个公共节点  LCOF)
// @Author: rubychen0611
// @Date: 2020-12-25 16:57:37
// @Runtime: 48 ms
// @Memory: 14.7 MB

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

