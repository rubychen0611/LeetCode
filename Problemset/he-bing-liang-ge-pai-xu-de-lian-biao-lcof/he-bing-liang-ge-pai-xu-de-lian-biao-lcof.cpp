
// @Title: 合并两个排序的链表 (合并两个排序的链表  LCOF)
// @Author: rubychen0611
// @Date: 2020-12-25 16:53:03
// @Runtime: 52 ms
// @Memory: 19.1 MB

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
    void addNode(ListNode* n)
    {
        n -> next = nullptr;
        if (head == NULL && tail == NULL)
            head = n;
        else
            tail -> next = n;
        tail = n;
    }
    void addList(ListNode* p)
    {
        if (head == NULL && tail == NULL)
            head = p;
        else
            tail -> next = p;
    }
public:
    Solution()
    {
        head = NULL;
        tail = NULL;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* p = l1, *q = l2, *temp;
        while(p != nullptr && q != nullptr)
        {
            if (p -> val <= q -> val)
            {
                temp = p;
                p = p -> next;
            }
            else if (q -> val <= p -> val)
            {
                temp = q;
                q = q -> next;
            }
            addNode(temp);
        }

        if (p != nullptr)
            addList(p);
        if(q != nullptr)
            addList(q);
        return head;
    }
};

