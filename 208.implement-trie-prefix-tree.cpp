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
    struct Node {
        bool isEnd;
        // maybe no use
        char val;
        Node* children[26];
        Node() {
            isEnd = false;
            memset(children, 0, sizeof(children));
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        // insert each character of the word
        for (int i = 0; i < word.size(); ++i) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new Node();
                curr->children[word[i] - 'a']->val = word[i];
            }
            // if it is the last character of the word
            if (i == word.size() - 1) {
                curr->children[word[i] - 'a']->isEnd = true;
            }
            curr = curr->children[word[i] - 'a'];
        }
    }
    
    bool search(string word) {
        Node *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                return false;
            }
            // if it is the last character of the word
            if (i == word.size() - 1 && curr->children[word[i] - 'a']->isEnd) {
                return true;
            }
            curr = curr->children[word[i] - 'a'];
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (curr->children[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[prefix[i] - 'a'];
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

