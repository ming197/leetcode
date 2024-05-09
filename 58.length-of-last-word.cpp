/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int res;
        // two pointers
        // this way can find all words
        // it is better to check from the last, it is more efficient
        while (j < n)
        {
            if (s[j] != ' ') {
                ++j;
            } else {
                if (i != j) {
                    res = j - i;
                }
                ++j;
                i = j;
            }
        }
        if (j == n && i != j) {
            res = j - i;
        }
        return res;
    }
};
// @lc code=end

