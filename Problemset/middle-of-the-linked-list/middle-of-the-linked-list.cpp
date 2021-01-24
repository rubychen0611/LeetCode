
// @Title: 链表的中间结点 (Middle of the Linked List)
// @Author: rubychen0611
// @Date: 2020-12-27 19:11:12
// @Runtime: 4 ms
// @Memory: 6.7 MB

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
    ListNode* middleNode(ListNode* head) {
        if (head -> next == NULL)
            return head;
        if (head -> next -> next == NULL)
            return head -> next;
        ListNode *slow = head, *fast=head;
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast -> next == NULL)
            return slow;
        else return slow -> next;
    }
};

