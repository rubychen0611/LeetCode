
// @Title: 链表相交 (Intersection of Two Linked Lists LCCI)
// @Author: rubychen0611
// @Date: 2020-12-25 17:00:01
// @Runtime: 80 ms
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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

