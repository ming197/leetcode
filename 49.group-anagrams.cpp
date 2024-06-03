/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        // key: the lowercase letter frequency of each string,
            // use a string of 26 characters to represent the frequency
        // value: the group of anagrams
        unordered_map<string, vector<string>> anagrams;
        for (string& str : strs)
        {
            string key(26, '0');
            for (char c : str)
            {
                ++key[c - 'a'];
            }
            anagrams[key].push_back(str);
        }
        vector<vector<string>> res;
        // iterate the map to get the result
        // structure binding, c++17
        for (auto& [_, group] : anagrams)
        {
            res.push_back(group);
        }
        return res;
    }
};
// @lc code=end

