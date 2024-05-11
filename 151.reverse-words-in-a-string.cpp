/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        std::reverse(s.begin(), s.end());
        // the first position to insert the character
        int start = 0;
        // two pointers
        int left = 0, right = 0;
        while (right < n)
        {
            if (s[right] == ' ') {
                // only when it is a word before the space
                if(left < right) {
                    // reverse the word to the suitable position
                    // to be insert [start, start + len)
                    // word to be reserved [left right)
                    std::reverse(s.begin() + left, s.begin() + right);
                    for (int i = left; i <right; ++i) {
                        s[start++] = s[i];
                    }
                    // add a single space
                    s[start++] = ' ';
                }
                // go to next character
                ++right;
                left = right;
            } else {
                ++right;
            }
        }
        // there exists one word to be reversed
        if(left < right) {
            std::reverse(s.begin() + left, s.begin() + right);
            for (int i = left; i <right; ++i) {
                s[start++] = s[i];
            }
        } else {
            // there exists one space at the end
            // remove the space
            --start;
        }
        return s.substr(0, start);
    }
};
// @lc code=end

