/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        // char2index: the index of the character in the string
        unordered_map<char, int> char2index;
        int maxLen = 0;
        while (++right < n + 1) {
            char c = s[right - 1];
            if (char2index.find(c) == char2index.end()) {
                maxLen = max(maxLen, right - left);
            } else {
                // the character is already in the substring
                // remove the character from the left to the index of the character
                int index = char2index[c];
                while (left <= index) {
                    char2index.erase(s[left++]);
                }
            }
            // update the index of the character
            char2index[c] = right - 1;
        }
        return maxLen;
    }
};
// @lc code=end

