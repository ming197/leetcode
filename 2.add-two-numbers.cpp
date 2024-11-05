/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head = new ListNode();
        ListNode *prev = dummy_head;
        int carry = 0;
        while (l1 && l2)
        {
            ListNode *new_node = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            prev->next = new_node;
            prev = new_node;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = l1 ? l1 : l2;
        while (l1)
        {
            ListNode *new_node = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            prev->next = new_node;
            prev = new_node;
            l1 = l1->next;
        }
        // if there is a carry left
        if (carry)
        {
            ListNode *new_node = new ListNode(carry);
            prev->next = new_node;
        }
        return dummy_head->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(1, new ListNode(8));
    ListNode* l2 = new ListNode(0);
    s.addTwoNumbers(l1, l2);
    return 0;
}
// @lc code=end

