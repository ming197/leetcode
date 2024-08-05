/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> result;
    string tmp_str = "";
    unordered_map<char, string> digit2string = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        // edge case
        if (digits.size() == 0) return result;
        DFS(digits, 0);
        return result;
    }
    void DFS(string &digits, int index) {
        if (index == digits.size()) {
            result.push_back(tmp_str);
            return;
        }
        for (char c : digit2string[digits[index]]) {
            tmp_str.push_back(c);
            DFS(digits, index + 1);
            tmp_str.pop_back();
        }
    }
};
// @lc code=end

