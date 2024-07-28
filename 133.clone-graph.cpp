/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<int, pair<Node*, Node*>> hash_table;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        queue<Node*> q;
        // clone the first node
        // ensure every node in the queue is copied
        Node* copy_head = new Node(node->val);
        hash_table[node->val] = make_pair(node, copy_head);
        q.push(node);
        while(!q.empty()) {
            Node *curr = q.front();
            Node *copy = hash_table[curr->val].second;
            q.pop();
            // copy the neighbors of the current node to the copy node
            for(auto neighbor : curr->neighbors) {
                int val = neighbor->val;
                Node* copy_neighbor;
                // BFS, push next node the queue
                // if not visited
                if (hash_table.find(val) == hash_table.end()) {
                    copy_neighbor = new Node(val);
                    hash_table[val] = make_pair(neighbor, copy_neighbor);
                    // push the original next node
                    q.push(neighbor);
                } else {
                    // if visited, just initialize the copy_neighbor
                    copy_neighbor = hash_table[val].second;
                }
                // update copy's neighbor
                copy->neighbors.push_back(copy_neighbor);
            }
        }
        return copy_head;
    }
};
// @lc code=end

