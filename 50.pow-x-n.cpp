/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        // if x is 1 or -1, then the result is 1 or -1
        if (x == 1 || x == -1) {
            return x == 1 ? 1 : (n % 2 == 0) ? 1 : -1;
        }
        // edge condition
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x * x;
        // if n is INT_MIN, then it will overflow
        if (n == INT_MIN) return 1 / myPow(x, INT_MAX) / myPow(x, 1);
        if (n < 0) return 1.0 / myPow(x, -1 * n);
        // if n is even, use the temp_result to store the result of x^(n/2)
        if (n % 2 == 0) {
            double temp_result = myPow(x, n / 2);
            return temp_result * temp_result;
        }
        return myPow(x, n / 2) * myPow(x, n - n / 2);
    }
};
// @lc code=end

