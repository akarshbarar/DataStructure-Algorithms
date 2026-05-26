class Solution {
public:
    int solveByRec(int start, int end) {
        if(start>=end) return 0;
        int ans = INT_MAX;
        for(int i= start; i<= end; i++) {
            ans = min(ans, i+ max(solveByRec(start, i-1), solveByRec(i+1, end)));
        }
        return ans;
    }

    int solveByMemo(int start, int end, vector<vector<int>> &dp) {
        if(start>=end) return 0;
        int ans = INT_MAX;
        if(dp[start][end] != -1) return dp[start][end];
        for(int i= start; i<= end; i++) {
            ans = min(ans, i+ max(solveByMemo(start, i-1, dp), solveByMemo(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }
    int solveByTab(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int start = n; start>=1; start--) {
            for(int end = start; end<=n; end++) {
                if(start == end) continue;
                int ans = INT_MAX;
                for(int i= start; i<= end; i++) {
                    ans = min(ans, i+ max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];

    }

    int getMoneyAmount(int n) {
        // return solveByRec(1,n);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveByMemo(1,n,dp);
        return solveByTab(n);
    }
};