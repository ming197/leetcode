/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.emplace(i);
                result.emplace_back(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &neighbor : graph[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                    result.emplace_back(neighbor);
                }
            }
        }
        return result.size() == numCourses ? result : vector<int>{};
    }
};
// @lc code=end

