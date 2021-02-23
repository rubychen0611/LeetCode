
// @Title: 删除排序链表中的重复元素 II (Remove Duplicates from Sorted List II)
// @Author: rubychen0611
// @Date: 2021-02-16 21:26:35
// @Runtime: 4 ms
// @Memory: 10.7 MB

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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(), *tail = dummy, *prev = nullptr, *p = head;
        int count = 0;
        while(p != nullptr)
        {
            if(prev && prev-> val == p -> val)  // 和前面重复
            {
                count ++;
            }
            else    // 和前一个不同
            {
                if(count == 1)  //前一个数只出现一次
                {
                    tail -> next = prev;
                    tail = prev;
                    prev -> next = nullptr;
                }
                count = 1;
            }
            prev = p;
            p = p -> next;
        }
        if(count == 1)
        {
            tail -> next = prev;
            tail = prev;
            prev -> next = nullptr;
        }
        return dummy -> next;
    }
};
