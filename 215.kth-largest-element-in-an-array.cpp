/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    // O(nlogk) time complexity
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};

class Solution {
public:
    // quick select, O(n) time complexity
    int findKthLargest(std::vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pivot_index = rand() % (right - left + 1) + left;
            int new_pivot_index = partition(nums, left, right, pivot_index);
            if (new_pivot_index == nums.size() - k) {
                return nums[new_pivot_index];
            } else if (new_pivot_index > nums.size() - k) {
                right = new_pivot_index - 1;
            } else {
                left = new_pivot_index + 1;
            }
        }
    }

private:
    int partition(std::vector<int>& nums, int left, int right, int pivot_index) {
        int pivot = nums[pivot_index];
        std::swap(nums[pivot_index], nums[right]);
        int stored_index = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[stored_index]);
                stored_index++;
            }
        }
        std::swap(nums[right], nums[stored_index]);
        return stored_index;
    }
};
// @lc code=end

