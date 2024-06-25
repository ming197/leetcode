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
        // if any list is empty, return another linked list
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        // create a dummy head node
        ListNode* dummyHead = new ListNode();
        ListNode* prev = dummyHead;
        int x = 0;
        // loop through both linked lists
        while (l1 && l2) {
            int val = (l1->val + l2->val + x) % 10;
            x = (l1->val + l2->val + x) / 10;
            prev->next = new ListNode(val);
            prev = prev->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // if any linked list is not empty, loop through it
        ListNode* l3 = l1 ? l1 : l2;
        // loop through the remaining linked list when one of the linked list is not empty or x > 0
        // pay attention to the condition in the while loop
        while (l3 || x > 0) {
            int y = l3 ? l3->val : 0;
            int val = (y + x) % 10;
            x = (y + x) / 10;
            prev->next = new ListNode(val);
            prev = prev->next;
            if (l3) l3 = l3->next;
        }

        return dummyHead->next;
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

