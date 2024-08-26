/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    // add two big numbers
    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += (carry & 1) + '0';
      carry >>= 1;
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
};
// @lc code=end

