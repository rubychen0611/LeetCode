
// @Title: 删除排序链表中的重复元素 (Remove Duplicates from Sorted List)
// @Author: rubychen0611
// @Date: 2020-12-25 15:37:12
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;
        ListNode* prev = head, *p = head -> next;
        while(p)
        {
            if (p -> val == prev -> val)
            {
                ListNode* tmp = p;
                prev -> next = p -> next;
                p = p -> next;
                delete tmp;
            }
            else
            {
                prev = p;
                p = p -> next;
            }
        }
        return head;
    }
};

