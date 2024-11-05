/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
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
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head = new ListNode();
        ListNode *prev_ptr = dummy_head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                prev_ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev_ptr->next = l2;
                l2 = l2->next;
            }
            prev_ptr = prev_ptr->next;
        }
        prev_ptr->next = l1 ? l1 : l2;
        return dummy_head->next;
    }
};
// @lc code=end

