/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // use bi-directional map to check the bijection of pattern and s
        unordered_map<char, string> pattern2s;
        unordered_map<string, char> s2pattern;
        // two pointers for string division
        int l = 0, r = 0;
        int n = s.size();
        int k = 0;
        int m = pattern.size();
        while (l < n && k < m)
        {
            while (r < n && s[r] != ' ')
            {
                ++r;
            }
            string word = s.substr(l, r - l);
            if (pattern2s.find(pattern[k]) == pattern2s.end() && s2pattern.find(word) == s2pattern.end())
            {
                pattern2s[pattern[k]] = word;
                s2pattern[word] = pattern[k];
            }
            else if (pattern2s[pattern[k]] != word || s2pattern[word] != pattern[k])
            {
                return false;
            }
            // update l and r
            l = r + 1;
            r = l;
            ++k;
        }
        return k == m && l == n + 1;
    }
};

int main()
{
    Solution sol;
    assert(sol.wordPattern("abba", "dog cat cat dog") == true);
    assert(sol.wordPattern("abba", "dog cat cat fish") == false);
    assert(sol.wordPattern("aaaa", "dog cat cat dog") == false);
    assert(sol.wordPattern("abba", "dog dog dog dog") == false);
    return 0;
}
// @lc code=end

