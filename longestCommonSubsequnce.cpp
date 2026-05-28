class Solution {
public:
    int solve(string a, string b, int i, int j) {
        if(i == a.length()) return 0;
        if(j == b.length()) return 0;
        int ans = 0;
        if(a[i] == b[j])
            ans =  1 + solve(a, b, i+1, j+1);
        else {
            ans =  max(solve(a, b, i+1, j), solve(a,b, i, j+1));
        }
        return ans;
    }
    int solveMemo(string a, string b, int i, int j, vector<vector<int>> &dp) {
        if(i == a.length()) return 0;
        if(j == b.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(a[i] == b[j])
            ans =  1 + solveMemo(a, b, i+1, j+1, dp);
        else {
            ans =  max(solveMemo(a, b, i+1, j, dp), solveMemo(a,b, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }
    int solveTab(string a, string b) {
        int n= a.length();
        int m = b.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i= n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + dp[i+1][j+1];
                else {
                    ans =  max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveTabSO(string a, string b) {
        int n= a.length();
        int m = b.length();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        for(int i= n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j])
                    ans =  1 + next[j+1];
                else {
                    ans =  max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solve(text1, text2, 0, 0);
        // int n= text1.length();
        // int m = text2.length();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return solveMemo(text1, text2, 0, 0, dp);
        return solveTabSO(text1, text2);
    }
};