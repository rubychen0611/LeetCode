
// @Title: 反转链表 (反转链表 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-19 09:30:00
// @Runtime: 4 ms
// @Memory: 8.1 MB

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
        if(head == nullptr)
            return nullptr;
        ListNode* cur = head, *next, *past = nullptr;
        if(next == nullptr)
            return head;
        while(cur != nullptr)
        {
            next = cur -> next;
            cur -> next = past;
            past = cur;
            cur = next;
        }
        return past;
    }
};
