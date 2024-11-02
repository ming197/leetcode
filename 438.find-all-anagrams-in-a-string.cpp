/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.size();
        int n = s.size();
        int left = 0, right = 0;
        // p_freq: the frequency of each character in p
        string p_freq = string(26, 0);
        for (char c : p) {
            p_freq[c - 'a']++;
        }
        vector<int> res;
        string s_freq = string(26, 0);
        while (++right < n + 1)
        {
            char c = s[right - 1];
            s_freq[c - 'a']++;
            if (right - left == len) {
                if (s_freq == p_freq) {
                    res.push_back(left);
                }
                // remove the character from the left
                s_freq[s[left++] - 'a']--;
            }
        }
        return res;
    }
};
// @lc code=end

