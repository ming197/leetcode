/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 1. a character can be replaced by any other character
        // 2. no two characters may map to the same character
        // the s2t to satisfy 1, use the t2s to satisfy 2
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i], c2 = t[i];
            if (s2t.find(c1) == s2t.end() && t2s.find(c2) == t2s.end()) {
                s2t[c1] = c2;
                t2s[c2] = c1;
            } else if (s2t[c1] != c2 || t2s[c2] != c1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

