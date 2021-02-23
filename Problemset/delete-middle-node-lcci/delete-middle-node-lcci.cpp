
// @Title: 删除中间节点 (Delete Middle Node LCCI)
// @Author: rubychen0611
// @Date: 2021-02-16 21:14:41
// @Runtime: 12 ms
// @Memory: 7.5 MB

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
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
