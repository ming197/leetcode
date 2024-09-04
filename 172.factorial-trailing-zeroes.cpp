/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) return 0;
        // count the number of 5 in n
        return n / 5 + trailingZeroes(n / 5);
    }
};
// @lc code=end

