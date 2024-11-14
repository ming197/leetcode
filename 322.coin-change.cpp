/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, amount + 1);
        minCoins[0] = 0;

        for (int i = 1; i <= amount; i++) {
            // iterate over all coins
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    // update minCoins[i] if we can use coins[j]
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
                }
            }
        }

        return minCoins[amount] != amount + 1 ? minCoins[amount] : -1;        
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // f[i] = min(f[i - coins[j]]) + 1
        // intitialize to amount + 1 to avoid overflow
        vector<int> f(amount + 1, amount + 1);
        f[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i)
                {
                    f[i] = min(f[i], 1 + f[i - coins[i]]);
                }
            }
        }
        return f[amount] != amount + 1 ? f[amount] : -1;
    }
};
// @lc code=end

