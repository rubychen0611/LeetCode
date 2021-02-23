
// @Title: 交换链表中的节点 (Swapping Nodes in a Linked List)
// @Author: rubychen0611
// @Date: 2021-02-16 21:05:58
// @Runtime: 708 ms
// @Memory: 175.8 MB

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head, *fast = head, *p1, *p2;
        for(int i = 1; i < k; i++)
            fast = fast -> next;
        p1 = fast;
        while(fast -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        p2 = slow;
        int tmp = p1 -> val;
        p1 -> val = p2 -> val;
        p2 -> val = tmp;
        return head;
    }
};
