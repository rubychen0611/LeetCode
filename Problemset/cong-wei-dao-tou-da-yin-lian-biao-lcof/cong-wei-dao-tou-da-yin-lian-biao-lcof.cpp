
// @Title: 从尾到头打印链表 (从尾到头打印链表 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-13 01:25:39
// @Runtime: 8 ms
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
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> st;
        ListNode* p = head;
        while(p)
        {
            st.push(p);
            p = p -> next;
        }
        vector<int> ans;
        while(!st.empty())
        {
            p = st.top();
            st.pop();
            ans.push_back(p -> val);
        }
        return ans;
    }
};
