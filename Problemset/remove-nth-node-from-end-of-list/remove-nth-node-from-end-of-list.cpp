
// @Title: 删除链表的倒数第N个节点 (Remove Nth Node From End of List)
// @Author: rubychen0611
// @Date: 2020-12-25 16:25:02
// @Runtime: 0 ms
// @Memory: 10.8 MB

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        for(int i = 0; i < n; i++)
            fast = fast -> next;
        while(fast != nullptr)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
        }
        if (!prev)  // 删除的是第一个节点
        {
            head = slow -> next;
        }
        else
        {
            prev -> next = slow -> next;
        }
        delete slow;
        return head;
    }
};

