
// @Title: 链表求和 (Sum Lists LCCI)
// @Author: rubychen0611
// @Date: 2020-12-28 10:38:08
// @Runtime: 44 ms
// @Memory: 69.7 MB

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
    ListNode* head, *tail;
    void addNode(int val)
    {
        ListNode* n = new ListNode(val);
        if (head == NULL && tail == NULL)
            head = n;
        else
            tail -> next = n;
        tail = n;
    }
public:
    Solution()
    {
        head = NULL;
        tail = NULL;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        int c = 0, sum;
        while(p1 && p2)
        {
            sum = p1 -> val + p2 -> val + c;
            addNode(sum % 10);
            c = sum / 10;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        while(p1)
        {
            sum = p1 -> val + c;
            addNode(sum % 10);
            c = sum / 10;
            p1 = p1 -> next;
        }
        while(p2)
        {
            sum = p2 -> val + c;
            addNode(sum % 10);
            c = sum / 10;
            p2 = p2 -> next;
        }
        if (c)
            addNode(c);
        return head;
    }
};

