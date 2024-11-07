/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class LRUCache {
public:
    struct ListNode {
        // key is used to find the node in the hash table
        // when we need to remove the least recently used item
        int key_;
        int value_;
        ListNode *prev_, *next_;
        ListNode(int key, int value) : key_(key), value_(value), prev_(this), next_(this) {}
    };
    // 1. need to get in O(1) time, so we need to use hash table
    // 2. need to remove the least recently used item in O(1) time, so we need to use double linked list
    //   a. remove the tail node in O(1) time
    //   b. add a new node to the head in O(1) time
    unordered_map<int, ListNode*> cache_;
    ListNode *dummy_head_ = new ListNode(-1, -1);
    int size_;
    int capacity_;
    LRUCache(int capacity) {
        size_ = 0;
        capacity_ = capacity;
        cache_.clear();
    }
    
    int get(int key) {
        auto iter = cache_.find(key);
        if (iter == cache_.end()) return -1;
        ListNode *node = iter->second;
        moveToHead(node);
        return node->value_;
    }
    
    void put(int key, int value) {
        auto iter = cache_.find(key);
        if (iter == cache_.end()) {
            ListNode *node = new ListNode(key, value);
            cache_[key] = node;
            addNode(node);
            size_++;
            if (size_ > capacity_) {
                // remove the least recently used item
                // 1. remove the tail node from the list
                // 2. remove the tail node in the hash table
                cache_.erase(dummy_head_->prev_->key_);
                removeTail();
                size_--;
            }
        } else {
            iter->second->value_ = value;
            moveToHead(iter->second);
        }
    }

    void addNode(ListNode *node) {
        // intialize the node's next and prev
        node->next_ = dummy_head_->next_;
        node->prev_ = dummy_head_;
        // update the dummy head's next and next's prev
        dummy_head_->next_->prev_ = node;
        dummy_head_->next_ = node;
    }

    void removeNode(ListNode *node) {
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
    }

    void moveToHead(ListNode *node) {
        // remove the node from the list
        removeNode(node);
        // add the node to the head
        addNode(node);
    }

    void removeTail() {
        removeNode(dummy_head_->prev_);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

