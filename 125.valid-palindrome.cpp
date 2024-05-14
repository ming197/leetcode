/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (l < r && toLower(s[l]) == ' ')
            {
                ++l;
            }
            while (l < r && toLower(s[r]) == ' ')
            {
                --r;
            }
            if (toLower(s[l]) != toLower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return c;
        }
        return ' ';
    }
};
// @lc code=end

