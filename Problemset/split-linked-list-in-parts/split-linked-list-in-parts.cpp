
// @Title: 分隔链表 (Split Linked List in Parts)
// @Author: rubychen0611
// @Date: 2021-01-03 17:16:45
// @Runtime: 12 ms
// @Memory: 9.3 MB

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0;
        ListNode* p = root, *tmp;
        vector<ListNode*> ans;
        while(p)
        {
            count ++;
            p = p -> next;
        }
        int interval = count / k, remain = count % k;
        p = root;
        for (int i = 0; i < remain; i++)
        {
            ans.push_back(p);
            for(int j = 0; j < interval; j++)
                p = p -> next;
            tmp = p;
            p = p -> next;
            tmp -> next = NULL;
        }
        for (int i = 0; i < k - remain; i++)
        {
            ans.push_back(p);
            if (!p) {
                continue;
            }
            for(int j = 0; j < interval - 1; j++)
                p = p -> next;
            tmp = p;
            p = p -> next;
            tmp -> next = NULL;
        }
        return ans;
    }
};

