
// @Title: 环形链表 (Linked List Cycle)
// @Author: rubychen0611
// @Date: 2021-02-16 21:52:27
// @Runtime: 12 ms
// @Memory: 8 MB

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast != nullptr && fast -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
