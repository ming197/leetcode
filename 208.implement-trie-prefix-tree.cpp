/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Trie {
public:
    struct Node
    {
        char val_;
        bool isLast_ = false;
        vector<Node*> children_;
        Node(char val) : val_(val), children_(26, nullptr) {}
    };
    Node *root = new Node('\0');
    Trie() {
        
    }
    
    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            auto ch = word[i];
            // if the current character is not in the children, create a new node
            if (!node->children_[ch - 'a'])
            {
                node->children_[ch - 'a'] = new Node(ch);
            }
            node = node->children_[ch - 'a'];
            if (i == word.size() - 1) {
                node->isLast_ = true;
            }
        }
    }
    
    bool search(string word) {
        Node *node = root;
        for (char ch : word) {
            if (node->children_[ch - 'a'])
            {
                node = node->children_[ch - 'a'];
            }
            else
            {
                return false;
            }
        }
        if (node->isLast_) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (char ch : prefix) {
            if (node->children_[ch - 'a'])
            {
                node = node->children_[ch - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

