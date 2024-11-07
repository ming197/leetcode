/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        // find the middle node
        ListNode *slow = head, *fast = head;
        // pre is the previous node of slow
        // pre is used to split the list into two parts
        ListNode *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre != nullptr) pre->next = nullptr;
        return merge(sortList(head), sortList(slow));
    }

    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy_head = new ListNode(0);
        ListNode *prev = dummy_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        l1 = l1 ? l1 : l2;
        prev->next = l1;
        return dummy_head->next;
    }
};
// @lc code=end

