/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution 
{
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        vector<pair<int, int>> pairs;
        for (auto i = 0; i < plantTime.size(); ++i)
            pairs.emplace_back(growTime[i], plantTime[i]);
        
        // nice trick with reverse iterators for reverse sorting
        sort(pairs.rbegin(), pairs.rend());
        
        int c = 0, t = 0;
        for (auto[g,p] : pairs) { c += p; t = max(t, c + g); }
        
        return t;
    }
};
// @lc code=end

