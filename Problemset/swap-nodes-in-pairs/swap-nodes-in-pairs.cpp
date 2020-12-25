
// @Title: 两两交换链表中的节点 (Swap Nodes in Pairs)
// @Author: rubychen0611
// @Date: 2020-12-25 14:05:46
// @Runtime: 0 ms
// @Memory: 7.8 MB

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* p = head, *prev = dummy, *remain;
        while(p != nullptr && p -> next != nullptr)
        {
            remain = p -> next -> next;
            prev -> next = p -> next;
            prev = p;
            p -> next -> next = p;
            p -> next = remain;
            p = remain;
        }
        return dummy -> next;
    }
};

