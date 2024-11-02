/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int &num : nums) {
            num_set.insert(num);
        }
        int longest_streak = 0;
        for (const int &num : nums) {
            // if the number is the start of a streak and the previous number is not in the set
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_streak = 1;
                while (num_set.find(current_num + 1) != num_set.end()) {
                    ++current_num;
                    ++current_streak;
                }
                longest_streak = max(longest_streak, current_streak);
            }
        }
        return longest_streak;
    }
};

// @lc code=end

