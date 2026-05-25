class Solution {
  public:
//   TC O(2^n)
    int solveByRec(int faces, int dice, int target) {
        if(target < 0) return 0;
        if(dice == 0 && target != 0) return 0;
        if(target == 0 && dice != 0) return 0;
        if(target == 0 && dice == 0) return 1;
        int ans = 0;
        for(int i=1; i<=faces; i++) {
            ans += solveByRec(faces, dice-1, target-i);
        }
        return ans;
    }
    // TC O(n*n) Sc O(n*n)
    int solveByMemo(int faces, int dice, int target, vector<vector<int>> &dp) {
        if(target < 0) return 0;
        if(dice == 0 && target != 0) return 0;
        if(target == 0 && dice != 0) return 0;
        if(target == 0 && dice == 0) return 1;
        if(dp[dice][target] != -1) return dp[dice][target];
        int ans = 0;
        for(int i=1; i<=faces; i++) {
            ans += solveByMemo(faces, dice-1, target-i, dp);
        }
        dp[dice][target] = ans;
        return dp[dice][target];
    }
    
    // TC (n*m*x) Sc (d*t)
    int solveByTab(int f, int d, int t) {
        vector<vector<int>> dp(d+1, vector<int>(t+1, 0));
        dp[0][0] = 1;
        for(int dice = 1; dice<=d; dice++) {
            for(int target =1; target<=t; target++) {
                int ans = 0;
                for(int i=1; i<=f; i++) {
                    if(target-i >=0)
                        ans += dp[dice-1][target-i];
                }
                dp[dice][target] = ans;
            }
        }
        return dp[d][t];
    }
    // TC O(nmx) Sc O(t)
    int solveByTabSO(int f, int d, int t) {
        vector<int> prev(t+1, 0);
        vector<int> curr(t+1, 0);
        prev[0] = 1;
        for(int dice = 1; dice<=d; dice++) {
            for(int target =1; target<=t; target++) {
                int ans = 0;
                for(int i=1; i<=f; i++) {
                    if(target-i >=0)
                        ans += prev[target-i];
                }
                curr[target] = ans;
            }
            prev = curr;
        }
        return curr[t];
    }
    
    int noOfWays(int m, int n, int x) {
        // code here
        // return solveByRec(m,n,x);
        // vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
        // return solveByMemo(m,n,x,dp);
        
                // return solveByTab(m,n,x);
                return solveByTabSO(m,n,x);

        
    }
};