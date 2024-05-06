/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class RandomizedSet {
    // store the elements in the set
    vector<int> v;
    // key: the element val, value: the indice in the vector
    unordered_map<int,int> mp;
public:
    RandomizedSet() {

    }
    // 1. how to implement getRandom? 
        // 1.1 use the vector to store the elements and use rand() to get the indice is a valid way
    // 2. how to acheive it in O(1) time
        // 2.1 insert element at the end of vector
        // 2.2 use map to store the indice, swap the element to the back and pop_back()
    bool search(int val) {
         return mp.find(val) == mp.end() ? false : true;
    }

    bool insert(int val) {
        if (search(val)) {
            return false;
        }
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)) {
            return false;
        }
        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

