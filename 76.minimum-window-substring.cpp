/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(n > m) return "";
        unordered_map<char, int> hash_table, temp_table;
        for(int i = 0; i < n; ++i){
            hash_table[t[i]]++;
        }
        int l = 0, r = -1;
        int res[2] = {0, m + 1};
        int cntValid = 0;
        while (++r < m)
        {
            temp_table[s[r]]++;
            // only when the frequency of the character in the window is less than or equal to the frequency of the character in the target string
            // the character is valid
            // otherwise, the character is redundant
            if(hash_table.find(s[r]) != hash_table.end() && hash_table[s[r]] >= temp_table[s[r]]){
                cntValid++;
            }
            while (cntValid == n && l <= r)
            {
                // update the result when the valid count is equal to the target string length
                if(r - l + 1 < res[1]){
                    res[0] = l;
                    res[1] = r - l + 1;
                }
                // move the left boudary of the window
                temp_table[s[l]]--;
                // update the valid count when the frequency of the character in the window is less than the frequency of the character in the target string
                if(hash_table.find(s[l]) != hash_table.end() && temp_table[s[l]] < hash_table[s[l]]){
                   cntValid--;
                }
                l++;
            }
        }
        return res[1] == m + 1 ? "" : s.substr(res[0], res[1]);
    }
};
// @lc code=end

