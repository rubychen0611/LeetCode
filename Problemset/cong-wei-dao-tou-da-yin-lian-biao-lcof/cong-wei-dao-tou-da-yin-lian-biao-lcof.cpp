
// @Title: 从尾到头打印链表 (从尾到头打印链表 LCOF)
// @Author: rubychen0611
// @Date: 2020-12-25 16:51:12
// @Runtime: 8 ms
// @Memory: 11.3 MB

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
    vector<int> reversePrint(ListNode* head) {

        if(head == NULL)
            return vector<int>();
        vector<int> ans = reversePrint(head -> next);
        ans.push_back(head -> val);
        return ans;
    }
};

