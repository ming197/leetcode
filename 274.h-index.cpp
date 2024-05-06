/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // cnt[h], papers count that has been cited more than h
        vector<int> cnt(1010, 0);
        int maxCitation = 0;;
        for (int& x : citations) {
            maxCitation = max(maxCitation, x);
            cnt[x]++;
        }
        if (cnt[maxCitation] >= maxCitation) {
            return maxCitation;
        }
        for (int h = maxCitation - 1; h > -1; --h) {
            cnt[h] += cnt[h + 1];
            if (cnt[h] >= h) {
                return h;
            }
        }
        return -1;
    }
};
// @lc code=end

