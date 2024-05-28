/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazine_map;
        for (char c : magazine) {
            magazine_map[c]++;
        }
        for (char c : ransomNote) {
            magazine_map[c]--;
            if (magazine_map[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

