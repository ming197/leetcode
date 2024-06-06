/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        // if n is not 1 and it is not in the set
        while (n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = next(n);
        }
        return n == 1;
    }

    int next(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end

