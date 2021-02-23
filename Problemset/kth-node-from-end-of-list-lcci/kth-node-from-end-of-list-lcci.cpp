
// @Title: 返回倒数第 k 个节点 (Kth Node From End of List LCCI)
// @Author: rubychen0611
// @Date: 2021-02-16 21:38:45
// @Runtime: 0 ms
// @Memory: 10 MB

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
    int kthToLast(ListNode* head, int k) {
        ListNode* slow = head, *fast = head, *p1, *p2;
        for(int i = 1; i < k; i++)
            fast = fast -> next;
        while(fast -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow -> val;
    }
};
