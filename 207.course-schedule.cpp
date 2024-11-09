/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        // graph: key is the prerequisite course, value is the course that depends on the key
        // the graph is represented by an adjacency list
        // it is a sparse graph, so we use unordered_map to store the graph
        unordered_map<int, vector<int>> graph;
        for (auto &p : prerequisites) {
            indegree[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }
        // BFS
        deque<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push_back(i);
            }
        }
        int cnt = q.size();
        while (!q.empty()) {
            int course = q.front();
            q.pop_front();
            for (auto &c : graph[course]) {
                indegree[c]--;
                if (indegree[c] == 0) {
                    q.push_back(c);
                    cnt++;
                }
            }
        }
        return cnt == numCourses;
    }
};
// @lc code=end

