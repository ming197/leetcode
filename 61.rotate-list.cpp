/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
#include "bits/stdc++.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (nullptr == head) {
            return head;
        }
        ListNode *node = head;
        int len = 1;
        while (node->next) {
            node = node->next;
            len++;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        // update the last node->next to head to make it a cycle
        node->next = head;
        k = len - k;
        // update the (len -k)th node->next to nullptr
        // to break the cycle
        while (k > 0)
        {
            node = node->next;
            --k;
        }
        ListNode *new_head = node->next;
        node->next = nullptr;
        return new_head;
    }
};

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* cur = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;        
    }
};

int main() {
    ListNode *head = new ListNode(0, new ListNode(1, new ListNode(2)));
    int k = 4;
    auto res = Solution().rotateRight(head, k);
    return 0;
}
// @lc code=end