
// @Title: 旋转链表 (Rotate List)
// @Author: rubychen0611
// @Date: 2020-12-27 17:25:15
// @Runtime: 8 ms
// @Memory: 12 MB

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;
        ListNode* p = head, *prev;
        int count = 0;
        while(p)
        {
            count++;
            prev = p;
            p = p -> next;
        }
        prev -> next = head;
        k = count - k % count;
        p = head;
        for (int i = 0; i < k; i++)
        {
            prev = p;
            p = p -> next;
        }
        prev -> next = nullptr;
        return p;

    }
};

