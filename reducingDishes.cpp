class Solution {
public:
    int solveByRecursion(vector<int> &sat, int index, int time){
        if (index == sat.size()) return 0;
        int include = sat[index]*(time+1) + solveByRecursion(sat, index+1, time+1); 
        int exclude = solveByRecursion(sat, index+1, time);
        int ans = max(include, exclude);
        return ans;
    }
    // Tc O(n*n) Sc (n*n)
      int solveByMemo(vector<int> &sat, int index, int time, vector<vector<int>> &dp){
        if (index == sat.size()) return 0;
        if (dp[index][time] != -1) return dp[index][time];
        int include = sat[index]*(time+1) + solveByMemo(sat, index+1, time+1, dp); 
        int exclude = solveByMemo(sat, index+1, time, dp);
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }

    int solveByTab(vector<int> &sat) {
        int n= sat.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int index = n - 1; index >=0; index--) {
            for(int time = index; time>=0; time--) {
                int include = sat[index]*(time+1) + dp[index+1][time+1]; 
                int exclude = dp[index+1][time];
                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    // TCO(n*n) SCO(n)
    int solveByTabSO(vector<int> &sat) {
        int n= sat.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        for(int index = n - 1; index >=0; index--) {
            for(int time = index; time>=0; time--) {
                int include = sat[index]*(time+1) + next[time+1]; 
                int exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(begin(satisfaction), end(satisfaction));
        // return solveByRecursion(satisfaction, 0, 0);
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return solveByMemo(satisfaction, 0, 0, dp);

        // return solveByTab(satisfaction);
        return solveByTabSO(satisfaction);
    }
};

// class Solution {
// public:
//     int maxSatisfaction(vector<int>& sat) {
//         sort(begin(sat), end(sat));
//         int run_sum = accumulate(begin(sat), end(sat), 0), total_sum = 0;
//         for (auto i = 0; i < sat.size(); ++i)
//             total_sum += (i + 1) * sat[i];
//         for (auto i = 0; run_sum < 0 && i < sat.size(); ++i) {
//             total_sum -= run_sum;
//             run_sum -= sat[i];
//         }
//         return total_sum;
//     }
// };