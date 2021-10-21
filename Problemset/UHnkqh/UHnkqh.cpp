
// @Title: 反转链表 (反转链表)
// @Author: rubychen0611
// @Date: 2021-10-08 20:02:32
// @Runtime: 8 ms
// @Memory: 8.2 MB

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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head, *prev = nullptr, *newhead = nullptr;
        while(p != nullptr) {
            prev = p;
            p = p -> next;
            prev -> next = newhead;
            newhead = prev;
        }
        return newhead;
    }
};
