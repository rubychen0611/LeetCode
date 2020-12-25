
// @Title: 回文链表 (Palindrome Linked List)
// @Author: rubychen0611
// @Date: 2020-12-25 15:25:15
// @Runtime: 28 ms
// @Memory: 14 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast -> next == NULL)   // 奇数
        {
            // 复制一个slow节点
            ListNode* n = new ListNode(slow->val);
            n -> next = slow -> next;
            slow -> next = NULL;
            return n;
        }
        else    // 偶数
        {
            ListNode* temp = slow -> next;
            slow -> next = NULL;
            return temp;
        }
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL, *remain, *p = head;
        while (p != NULL)
        {
            remain = p -> next;
            p -> next = prev;
            prev = p;
            p = remain;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return true;
        ListNode* mid = findMid(head);
        ListNode* reversed_mid = reverseList(mid);
        ListNode* p = head, *q = reversed_mid;
        while(p && q && p -> val == q ->val)
        {
            p = p -> next;
            q = q -> next;
        }
        if (p == NULL && q == NULL)
            return true;
        return false;
    }
};

