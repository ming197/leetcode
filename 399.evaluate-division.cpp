/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // need to judge whether any two nodes are connected
        // if not, return -1.0
        // if connected, return the value of the path

        // build the DAG by the unordered_map
        unordered_map<string, unordered_map<string, double>> graph;
        int n = equations.size();
        for (int i = 0; i < n; ++i)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double k = values[i];
            graph[a][b] = k;
            graph[b][a] = 1.0 / k;
        }
        vector<double> res;
        for (auto &query : queries)
        {
            string a = query[0];
            string b = query[1];
            if (!graph.count(a) || !graph.count(b))
            {
                res.push_back(-1.0);
                continue;
            }
            // if a == b, the result is 1.0
            if (a == b)
            {
                res.push_back(1.0);
                continue;
            }
            // BFS to find the path
            // flag to judge whether the node is visited
            unordered_set<string> visited;
            // store the node and the value of the path
            queue<pair<string, double>> q;
            q.push({a, 1.0});
            visited.insert(a);
            bool found = false;
            double ans = -1.0;
            while (!q.empty())
            {
                auto [node, val] = q.front();
                q.pop();
                if (node == b)
                {
                    ans = val;
                    found = true;
                    break;
                }
                for (auto &[next, k] : graph[node])
                {
                    if (visited.count(next))
                    {
                        continue;
                    }
                    visited.insert(next);
                    q.push({next, val * k});
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
// @lc code=end

