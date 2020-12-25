
// @Title: 链表中倒数第k个节点 (链表中倒数第k个节点 LCOF)
// @Author: rubychen0611
// @Date: 2020-12-25 16:56:17
// @Runtime: 8 ms
// @Memory: 10.8 MB

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        for(int i = 0; i < k; i++)
            fast = fast -> next;
        while(fast != nullptr)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }
};

