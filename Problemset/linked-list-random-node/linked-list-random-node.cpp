
// @Title: 链表随机节点 (Linked List Random Node)
// @Author: rubychen0611
// @Date: 2021-03-03 16:16:32
// @Runtime: 32 ms
// @Memory: 16.2 MB

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
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this -> head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans;
        int count = 0;
        ListNode* p = head;
        while(p)
        {
            count ++;
            int random = rand() % count + 1; // 1~count之间的随机数
            if(random == 1)
                ans = p -> val;
            p = p -> next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
