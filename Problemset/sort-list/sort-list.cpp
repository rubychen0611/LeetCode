
// @Title: 排序链表 (Sort List)
// @Author: rubychen0611
// @Date: 2020-12-25 16:43:31
// @Runtime: 148 ms
// @Memory: 28.9 MB

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
private:
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = nullptr;
        return temp;
    }
    void addNode(ListNode* &head, ListNode* & tail, ListNode* n)
    {
        n -> next = nullptr;
        if (head == nullptr && tail == nullptr)
            head = n;
        else
            tail -> next = n;
        tail = n;
    }
    void addList(ListNode* &head, ListNode* & tail, ListNode* p)
    {
        if (head == nullptr && tail == nullptr)
            head = p;
        else
            tail -> next = p;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* head = nullptr, *tail = nullptr;
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
            addNode(head, tail, temp);
        }

        if (p != nullptr)
            addList(head, tail, p);
        if(q != nullptr)
            addList(head, tail, q);
        return head;
    }

public:
    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr || head -> next == nullptr)
            return head;
        ListNode* mid = findMid(head);
        ListNode* h1 = sortList(head), *h2 = sortList(mid);
        return mergeTwoLists(h1, h2);
    }
};

