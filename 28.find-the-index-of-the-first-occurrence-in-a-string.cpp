/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = 0, r = 0;
        int n = haystack.size();
        int m = needle.size();
        while (l < n)
        {
            while (r < n && r - l < m && haystack[r] == needle[r - l])
            {
                ++r;
            }
            if(r - l == m) {
                return l;
            }
            ++l;
            r = l;
        }
        return -1;
    }
};
// @lc code=end

