/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int word_len = words[0].size();
        int sub_string_len = word_len * words.size();
        // the map to store the words and their frequency
        unordered_map<string, int> map;
        for (const string& word : words) {
             map[word]++;
        }

        // iterate for each offset
        for (int offset = 0; offset < word_len; offset++) {
            // Sliding window memory.
            unordered_map<string, int> seen;
            // regard each word as a unit, so the window size is the number of words
            // [l, r) is the window, r is the right boundary, l is the left boundary
            int l = offset, r = offset;
            while (l <= r && r <= s.size())
            {
                // if the window size is equal to the sub_string_len, we find a valid substring
                if (r - l == sub_string_len) {
                    res.push_back(l);
                    // remove the leftmost word
                    // go to the next iteration
                    seen[s.substr(l, word_len)]--;
                    l += word_len;
                } else {
                    if (r + word_len - 1 < s.size()) {
                        string sub_str = s.substr(r, word_len);
                        if (map.find(sub_str) != map.end()) {
                            seen[sub_str]++;
                            r += word_len;
                            // check the frequency of the sub_str
                            while (seen[sub_str] > map[sub_str]) {
                                seen[s.substr(l, word_len)]--;
                                l += word_len;
                            }
                        } else {
                            // if the word is not in the words, we need to reset the window
                            seen.clear();
                            l = r + word_len;
                            r = l;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words = {"foo", "bar"};
    vector<int> res = s.findSubstring("barfoothefoobarman", words);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
// @lc code=end

