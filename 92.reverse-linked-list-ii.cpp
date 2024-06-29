/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy_head = new ListNode(0, head);
        // the node before node_idx
        ListNode *node = dummy_head;
        int index = 1;
        // find the left node
        // node will be the sentinel node of the reversed interval
        while (index < left) {
            node = node->next;
            index++;
        }
        // reverse the interval
        ListNode *curr = node->next;
        ListNode *prev = nullptr;
        // reverse the nodes from left to right
        // curr will be the next of right node
        for (index = left; index <= right; index++) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // the tail after reverse
        ListNode *tail = node->next;
        node->next = prev;
        tail->next = curr;
        // cannot return head, because head may the reversed node
        // return the next of dummy_head
        return dummy_head->next;
    }
};

int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(5);
    Solution s;
    s.reverseBetween(head, 1, 2);
    return 0;
}
// @lc code=end

