/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> val2freq;
        for (int i = 0; i < n; i++)
        {
            val2freq[nums[i]]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto it = val2freq.begin(); it != val2freq.end(); it++)
        {
            min_heap.push({it->second, it->first});
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
        while (!min_heap.empty())
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
// @lc code=end

