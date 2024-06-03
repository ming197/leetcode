/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        // check the length of two strings first
        if (s.size() != t.size())
        {
            return false;
        }
        // count the frequency of each character
        vector<int> count(26, 0);
        for (char c : s)
        {
            ++count[c - 'a'];
        }
        for (char c : t)
        {
            --count[c - 'a'];
            // if the count is negative, return false
            if (count[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

