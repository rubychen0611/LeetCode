
// @Title: 合并K个升序链表 (Merge k Sorted Lists)
// @Author: rubychen0611
// @Date: 2021-01-07 21:11:25
// @Runtime: 44 ms
// @Memory: 13.3 MB

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
// 法1： 利用归并排序算法，两两合并
/*
class Solution_Two{
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
    Solution_Two()
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

class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
            return nullptr;
        ListNode* ans = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            Solution_Two s2;
            ans = s2.mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};
*/
// 法2：优先队列

struct Comp
{
    bool operator() (ListNode* l1, ListNode* l2)
    {
        return l1 -> val > l2 -> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
            return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        for(ListNode* list: lists)
        {
            if(list)
                q.push(list);
        }
        ListNode* dummy = new ListNode(0), *cur = dummy;
        while(!q.empty())
        {
            cur -> next = q.top();
            q.pop();
            cur = cur -> next;
            if(cur->next)
                q.push(cur->next);

        }
        return dummy -> next;
    }
};

