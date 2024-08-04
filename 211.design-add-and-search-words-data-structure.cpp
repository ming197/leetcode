/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class WordDictionary {
public:
    struct Node {
        Node* children[26];
        // just for the last character of the word
        bool isEnd;
        Node() {
            isEnd = false;
            memset(children, 0, sizeof(children));
        }
    };
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *current_node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (current_node->children[word[i] - 'a'] == nullptr) {
                current_node->children[word[i] - 'a'] = new Node();
            }
            if (i == word.size() - 1) {
                current_node->children[word[i] - 'a']->isEnd = true;
            }
            current_node = current_node->children[word[i] - 'a'];
        }
    }
    
    bool search(string word) {
        queue<Node*> q;
        q.push(root);
        for (int k = 0; k < word.size(); ++k) {
            char c = word[k];
            int n = q.size();
            // BFS
            for (int i = 0; i < n; ++i) {
                Node* current_node = q.front();
                q.pop();
                if (c == '.') {
                    for (int j = 0; j < 26; ++j) {
                        if (current_node->children[j] != nullptr) {
                            q.push(current_node->children[j]);
                            if (k == word.size() - 1 && current_node->children[j]->isEnd) {
                                return true;
                            }
                        }
                    }
                } else {
                    if (current_node->children[c - 'a'] != nullptr) {
                        q.push(current_node->children[c - 'a']);
                        if (k == word.size() - 1 && current_node->children[c - 'a']->isEnd) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

