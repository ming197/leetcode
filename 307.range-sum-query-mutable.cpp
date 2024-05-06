/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class NumArray {
public:
    vector<int> bit;
    vector<int> data;

    int lowBit(int x){
        return x & (-x);
    }

    int sum(int idx){
        int res = 0;
        while (idx > 0)
        {
            /* code */
            res += bit[idx];
            idx -= lowBit(idx);
        }
        return res;
    } 

    NumArray(vector<int>& nums) {
        bit = vector<int>(nums.size() + 1, 0);

        data = nums;
        for(int i = 1; i < nums.size() + 1; ++i){
            bit[i] += nums[i - 1];
            int j = i + lowBit(i);
            if(j <= nums.size()) bit[j] += bit[i]; 
        }
    }
    
    void update(int index, int val) {
        int diff = val - data[index];
        data[index] = val;
        ++index;
        while (index <= data.size())
        {
            /* code */
            bit[index] += diff;
            index += lowBit(index);
        }
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

