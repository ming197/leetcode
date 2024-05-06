/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        // use left and right iteration to guarantee 
        // 1. more candidates than left if have a higher rating
        // 2. more candidates than right if have a higher rating
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);
        int ans = 0;
        // min candidates to satisfy left
        for(int i = 1; i < ratings.size(); ++i)
        {
            if(ratings[i - 1] < ratings[i])
            {
                left[i] = left[i - 1] + 1;
            }
        }
        // min candidates to satisfy right
        for(int i = ratings.size() - 1; i > 0; --i)
        {
            if(ratings[i-1] > ratings[i])
            {
                right[i-1] = right[i] + 1;
            }
        }
        for(int i = 0; i < ratings.size(); ++i)
        {
            ans += max(left[i] ,right[i]);   
        }
        return ans;
    }
};
// @lc code=end

