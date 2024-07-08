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
        int key;
        int value;
        ListNode *prev;
        ListNode *next;
        ListNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    };
    // 1. need to get in O(1) time, so we need to use hash table
    // 2. put in O(1) time, so we need to use double linked list
    //  a. add the node to the head in O(1) time
    //  b. remove the tail in O(1) time
    unordered_map<int, ListNode*> cache_node_;
    ListNode *dummy_head_;
    int capacity_;
    int size_;
    LRUCache(int capacity) {
        dummy_head_ = new ListNode(-1, -1);
        dummy_head_->prev = dummy_head_;
        dummy_head_->next = dummy_head_;
        capacity_ = capacity;
        size_ = 0;
        cache_node_.clear();
    }
    
    int get(int key) {
        if (cache_node_.find(key) == cache_node_.end()) {
            return -1;
        }
        ListNode *node = cache_node_[key];
        // update the node to the head
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache_node_.find(key) != cache_node_.end()) {
            // update the value of the node
            cache_node_[key]->value = value;
            // update the node to the head
            moveToHead(cache_node_[key]);
            return;
        } else {
            ListNode *node = new ListNode(key, value);
            addNode(node);
            cache_node_[key] = node;
            size_++;
            if (size_ > capacity_) {
                removeTail();
                size_--;
            }
        }
    }

    void addNode(ListNode *node) {
        node->prev = dummy_head_;
        node->next = dummy_head_->next;
        dummy_head_->next->prev = node;
        dummy_head_->next = node;
    }

    void moveToHead(ListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = dummy_head_;
        node->next = dummy_head_->next;
        dummy_head_->next->prev = node;
        dummy_head_->next = node;
    }

    void removeTail() {
        // tail cannot be dummy_head_
        ListNode *tail = dummy_head_->prev;
        tail->prev->next = dummy_head_;
        dummy_head_->prev = tail->prev;
        cache_node_.erase(tail->key);
        delete tail;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

