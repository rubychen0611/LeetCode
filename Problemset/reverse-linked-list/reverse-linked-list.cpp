
// @Title: 反转链表 (Reverse Linked List)
// @Author: rubychen0611
// @Date: 2020-12-24 21:06:36
// @Runtime: 8 ms
// @Memory: 8.5 MB

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL, *curr = head, *next;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

