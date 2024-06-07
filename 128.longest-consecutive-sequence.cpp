/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        // sort the array
        sort(nums.begin(), nums.end());
        int currentConsecutiveSequence = 1;
        int longestConsecutiveSequence = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                // check if the current element is consecutive
                if(nums[i] == nums[i-1] + 1){
                    currentConsecutiveSequence++;
                }
                else{
                    // if not consecutive, update the longestConsecutiveSequence
                    longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                    currentConsecutiveSequence = 1;
                }
            }
        }
        return max(longestConsecutiveSequence, currentConsecutiveSequence);
    }
};

// @lc code=end

