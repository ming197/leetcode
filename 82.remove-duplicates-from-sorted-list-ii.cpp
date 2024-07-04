/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *dummy_head = new ListNode(-101, head);
        ListNode *prev = dummy_head;
        ListNode *cur = head;
        ListNode *next = head->next;
        // prev->val must be less than cur->val
        // so if next is nullptr, cur is the last node, we can end the loop
        while (cur != nullptr && next != nullptr) {
            if (next->val == cur->val) {
                while (next && next->val == cur->val) {
                    next = next->next;
                }
                // next->val != cur->val
                prev->next = next;
                cur = next;
                if (next) {
                    next = next->next;
                }
            } else {
                prev = cur;
                cur = next;
                next = next->next;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end

