
// @Title: 环形链表 II (Linked List Cycle II)
// @Author: rubychen0611
// @Date: 2020-12-27 16:25:57
// @Runtime: 8 ms
// @Memory: 7.9 MB

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL)
            return nullptr;
        ListNode* slow = head, *fast = head;
        bool flag = false;
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            fast = head;    // 如果此时slow fast已经等于head了，则不进入循环
            while(slow != fast)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
            return fast;
        }
        else return nullptr;
    }
};

