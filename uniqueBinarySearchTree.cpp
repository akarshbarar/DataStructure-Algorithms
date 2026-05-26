class Solution {
public:
    int solveByRec(int n) {
        if(n<=1) return 1;
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = ans + solveByRec(i-1)*solveByRec(n-i);
        }
        return ans;
    }
    int solveByMemo(int n, vector<int> &dp) {
        if(n<=1) return 1;
        int ans = 0;
        if(dp[n] != -1) return dp[n];
        for(int i=1; i<=n; i++) {
            ans = ans + solveByRec(i-1)*solveByRec(n-i);
        }
        dp[n] = ans;
        return dp[n];
    }

    int solveByTab(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                dp[i] = dp[i] + dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        // return solveByRec(n);
        // vector<int> dp(n+1, -1);
        // return solveByMemo(n, dp);
        return solveByTab(n);
        // its is also catalan number can be solved by (2n!)/((n+1)!* n!)
    }
};