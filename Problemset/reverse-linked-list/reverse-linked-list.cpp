
// @Title: 反转链表 (Reverse Linked List)
// @Author: rubychen0611
// @Date: 2018-07-10 13:41:07
// @Runtime: 8 ms
// @Memory: N/A


class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		if(head == NULL || head-> next == NULL)
			return head;
		ListNode* plast = reverseList(head -> next);
		ListNode* p = plast; 
		head-> next ->next = head;
		head -> next = NULL;
		return plast;
	}
}; 
