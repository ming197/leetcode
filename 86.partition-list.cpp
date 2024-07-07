/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return head;
        }
        ListNode *dummy_head1 = new ListNode();
        ListNode *dummy_head2 = new ListNode();
        ListNode *cur1 = dummy_head1;
        ListNode *cur2 = dummy_head2;
        // insert one node after the current node
        while (head)
        {
            if (head->val < x) {
                cur1->next = head;
                cur1 = cur1->next;
            } else {
                cur2->next = head;
                cur2 = cur2->next;
            }
            head = head->next;
        }
        // link the last node of cur1 to the first node of cur2
        cur1->next = dummy_head2->next;
        // update the last node of cur2
        cur2->next = nullptr;
        return dummy_head1->next;
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    s.partition(head, 3);
    return 0;
}
// @lc code=end

