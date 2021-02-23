
// @Title: 删除链表的节点 (删除链表的节点 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-16 20:36:17
// @Runtime: 16 ms
// @Memory: 9.1 MB

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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p = head, *prev = nullptr;
        while(p != nullptr)
        {
            if(p -> val == val)
            {
                if(prev == nullptr)
                {
                    head = head -> next;
                    return head;
                }
                else
                {
                    prev -> next = p -> next;
                    return head;
                }
            }
            prev = p;
            p = p -> next;
        }
        return head;
    }
};
