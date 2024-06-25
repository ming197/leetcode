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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // dummy head
        ListNode* dummyHead = new ListNode();
        ListNode* previous_ptr = dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                previous_ptr->next = l1;
                previous_ptr = previous_ptr->next;
                l1 = l1->next;
            } else {
                previous_ptr->next = l2;
                previous_ptr = previous_ptr->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            previous_ptr->next = l1;
        } else {
            previous_ptr->next = l2;
        }
        return dummyHead->next;
    }
};
// @lc code=end

