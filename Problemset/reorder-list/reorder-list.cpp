
// @Title: 重排链表 (Reorder List)
// @Author: rubychen0611
// @Date: 2020-12-28 15:29:30
// @Runtime: 760 ms
// @Memory: 17.8 MB

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
    void reorderList(ListNode* head) {
        ListNode* p = head, *q=p, *tmp, *prev=p;
        while(p)
        {
            q = p;
            while(q-> next)
            {
                prev = q;
                q = q -> next;
            }
            prev -> next = NULL;
            tmp = p;
            p = p -> next;
            tmp -> next = q;
            q -> next = p;
        }
        return;
    }
};
