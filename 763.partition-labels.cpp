/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last(26, 0);
        // Store the last index of each character
        for (int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
        }
        vector<int> res;
        // start and end are the start and end of the current partition
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
    }
};
// @lc code=end

