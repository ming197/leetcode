#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int> > f(n, vector<int>(d, 1e6 + 10));
        
        int max_difficulty = jobDifficulty[0];
        for(int i = 0; i < n; ++i){
            max_difficulty = max(max_difficulty, jobDifficulty[i]);
            f[i][0] = max_difficulty;
        }
        
        for(int i = 1; i < n; ++i){
            for(int j = 1; j <= i && j < d; ++j){
                // k jobs at day_j, [1, i]
                int maxDifficulty = jobDifficulty[i];
                for(int k = 1; i - k >= j - 1; ++k){
                    //  maxDifficulty from i to i - k + 1
                    maxDifficulty = max(maxDifficulty, jobDifficulty[i - k + 1]);
                    f[i][j] = min(f[i][j], f[i - k][j - 1] + maxDifficulty);
                    
                    
                }
            }
        }
        
        return f[n - 1][d - 1];
    }
};
