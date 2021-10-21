
// @Title: 两个链表的第一个重合节点 (两个链表的第一个重合节点)
// @Author: rubychen0611
// @Date: 2021-10-08 19:43:25
// @Runtime: 36 ms
// @Memory: 14.3 MB

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
        ListNode* p1 = headA, * p2 = headB;
        bool p1_changed = false, p2_changed = false;
        while(p1 != NULL && p2 != NULL) {
            if(p1 == p2) {
                return p1;
            }
            p1 = p1 -> next;
            if(p1 == NULL && !p1_changed) {
                p1_changed = true;
                p1 = headB;
            }
            p2 = p2 -> next;
            if(p2 == NULL && !p2_changed) {
                p2_changed = true;
                p2 = headA;
            }
        }
        return NULL;
    }
};
