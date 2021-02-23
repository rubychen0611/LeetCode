
// @Title: 有序链表转换二叉搜索树 (Convert Sorted List to Binary Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-12 14:13:05
// @Runtime: 36 ms
// @Memory: 30.2 MB

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode* findMid(ListNode* head)
    {
        ListNode* p1 = head, *p1_prev = head, *p2 = head;
        while(p2 && p2 -> next)
        {
            p1_prev = p1;
            p1 = p1 -> next;
            p2 = p2 -> next -> next;
        }
        p1_prev -> next = nullptr;
        return p1;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* mid = findMid(head);
       //cout << mid -> val << endl;
        TreeNode* root = new TreeNode(mid -> val);
        if(head == mid)
            root -> left = nullptr;
        else
            root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(mid -> next);
        return root;
    }
};
