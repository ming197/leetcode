/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        // use map to store key-value
        std::unordered_map<char, int> myMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int n = s.size();
        int i = -1;
        int res = 0;
        int preVal = 0;
        while (++i < n)
        {
            // only no-decrease, plus value
            if (i == n - 1 || myMap[s[i]] >= myMap[s[i + 1]]) {
                res += myMap[s[i]] - preVal;
                preVal = 0;
            } else { // or substract the val, use preVal to accumulate
                preVal += myMap[s[i]];
            }

        }
        return res;
    }
};
// @lc code=end

