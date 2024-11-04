/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *dummy_head = new ListNode(-1, nullptr);
        ListNode *ptr = head;
        // insert the node after the dummy_head
        while (ptr)
        {
            ListNode *next = ptr->next;
            ptr->next = dummy_head->next;
            dummy_head->next = ptr;
            ptr = next;
        }
        return dummy_head->next;
    }
};
// @lc code=end

