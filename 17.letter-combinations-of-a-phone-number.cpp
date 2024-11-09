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
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        string temp("");
        backtrack(digits, 0, temp);
        return result;
    }

    void backtrack(string &digits, int k, string &temp) {
        if (temp.size() == digits.size()) {
            result.push_back(temp);
            return;
        }
        for (char c : digit2string[digits[k]]) {
            temp.push_back(c);
            backtrack(digits, k + 1, temp);
            temp.pop_back();
        }
    }

};
// @lc code=end

