
// @Title: 二进制链表转整数 (Convert Binary Number in a Linked List to Integer)
// @Author: rubychen0611
// @Date: 2020-12-28 10:31:33
// @Runtime: 4 ms
// @Memory: 8.7 MB

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
    int getDecimalValue(ListNode* head) {
        if (head == NULL)
            return 0;
        int count = 0;
        ListNode* p = head;
        while(p)
        {
            count ++;
            p = p -> next;
        }
        int ans = 0;
        p = head;
        while(p)
        {
            count --;
            if (p -> val == 1)
                ans += pow(2,count);
            p = p -> next;
        }
        return ans;
    }
};

