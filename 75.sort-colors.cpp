/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        // p0 is the first index of 1, p2 is the last index of 1
        while (p0 < n && nums[p0] == 0) ++p0;
        while (p2 >= 0 && nums[p2] == 2) --p2;
        for (int i = p0; i <= p2;)
        {
            // nums[i] == 0, swap with nums[p0], p0++, i++
            if (nums[i] == 0)
            {
                swap(nums[i], nums[p0]);
                ++p0;
                ++i;
            }
            // nums[i] == 2, swap with nums[p2], p2--
            // i don't move, because nums[p2] is unknown
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                --p2;
            }
            else
            {
                ++i;
            }
        }
    }
};
// @lc code=end

