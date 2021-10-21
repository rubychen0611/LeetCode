
// @Title: 链表中环的入口节点 (链表中环的入口节点)
// @Author: rubychen0611
// @Date: 2021-10-08 19:34:21
// @Runtime: 8 ms
// @Memory: 7.6 MB

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) {
                fast = head;
                while(true) {
                    if(fast == slow)
                        return fast;
                    fast = fast -> next;
                    slow = slow -> next;
                }
            }
        }
//        if(fast == nullptr || fast ->next == nullptr)
//            return nullptr;
        return nullptr;
    }
};

