
// @Title: 删除链表中的节点 (Delete Node in a Linked List)
// @Author: rubychen0611
// @Date: 2020-12-27 18:58:29
// @Runtime: 8 ms
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
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

