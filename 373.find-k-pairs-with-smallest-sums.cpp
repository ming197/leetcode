/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Min priority queue (min-heap) for storing pairs {sum, index_in_nums2}
        // The heap is ordered by the sum
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Result vector to store the k smallest pairs
        vector<vector<int>> ans;

        // Initialize the heap with pairs (nums1[i] + nums2[0], 0) for all elements in nums1
        for (int i : nums1) {
            pq.push({i + nums2[0], 0});
        }
        // the height of the heap is O(log(n))
        // Extract the smallest pairs from the heap k times or until the heap is empty
        while (k-- && !pq.empty()) {
            // Get the smallest pair sum and the index in nums2
            int sum = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            // Extract the actual elements from nums1 and nums2
            ans.push_back({sum - nums2[pos], nums2[pos]});

            // If there are more elements in nums2, push the next pair into the heap
            if (pos + 1 < nums2.size()) {
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        } 
        
        return ans;
    }
};
// @lc code=end

