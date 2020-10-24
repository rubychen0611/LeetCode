
// @Title: 合并两个有序链表 (Merge Two Sorted Lists)
// @Author: rubychen0611
// @Date: 2018-07-10 13:27:41
// @Runtime: 24 ms
// @Memory: N/A

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
	void addList(ListNode* n)
	{
		n->next = NULL;
		if (head == NULL)
			head = n;
		else
			tail->next = n;
		tail = n;
	}
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		head = NULL; tail = NULL;
		ListNode* p1 = l1, *p2 = l2;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val <= p2->val)
			{
				ListNode* n = new ListNode(p1->val);
				addList(n);
				p1 = p1->next;
			}
			else
			{
				ListNode* n = new ListNode(p2->val);
				addList(n);
				p2 = p2->next;
			}
		}
		while (p1 != NULL)
		{
			ListNode* n = new ListNode(p1->val);
			addList(n);
            p1 = p1->next;
		}
		while (p2 != NULL)
		{
			ListNode* n = new ListNode(p2->val);
			addList(n);
            p2 = p2->next;
		}
		return head;
	}
};
