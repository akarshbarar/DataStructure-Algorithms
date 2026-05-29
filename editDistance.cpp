class Solution {
public:
    int solve(string &a, string &b, int i, int j) {
        if(a.length() == i) return b.length() - j;
        if(b.length() == j) return a.length() - i;
        int ans = 0;
        if(a[i] == b[j]){
            return solve(a, b, i+1, j+1);
        }
        else {
            int insertAns = 1 + solve(a, b, i, j+1);
            int deleteAns = 1 + solve(a,b, i+1, j);
            int replaceAns = 1 + solve(a,b, i+1, j+1);
            ans = min(insertAns, min(deleteAns,replaceAns));
        }
        return ans;
    }

    int solveMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if(a.length() == i) return b.length() - j;
        if(b.length() == j) return a.length() - i;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(a[i] == b[j]){
            return solveMemo(a, b, i+1, j+1, dp);
        }
        else {
            int insertAns = 1 + solveMemo(a, b, i, j+1, dp);
            int deleteAns = 1 + solveMemo(a,b, i+1, j, dp);
            int replaceAns = 1 + solveMemo(a,b, i+1, j+1, dp);
            ans = min(insertAns, min(deleteAns,replaceAns));
        }
        return dp[i][j] = ans;
    }

    int solveTab(string &a, string &b) {
        int n= a.length();
        int m = b.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // dp[n-1][m-1] = 0
        for(int j=0; j<b.length(); j++) {
            dp[n][j] = b.length() - j;
        }
        for(int i=0; i<a.length(); i++) {
            dp[i][m] = a.length() - i;
        }

        for(int i= n-1; i>=0; i--) {
            for(int j= m-1; j>=0; j--) {
                int ans = 0;
                if(a[i] == b[j]){
                    ans =  dp[i+1][j+1];
                }
                else {
                    int insertAns = 1 + dp[i][j+1];
                    int deleteAns = 1 + dp[i+1][j];
                    int replaceAns = 1 + dp[i+1][j+1];
                    ans = min(insertAns, min(deleteAns,replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

int solveTabSO(string &a, string &b) {
        int n= a.length();
        int m = b.length();

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for(int j=0; j<b.length(); j++) {
            next[j] = b.length() - j;
        }

        for(int i= n-1; i>=0; i--) {
            for(int j= m-1; j>=0; j--) {
                curr[m] = a.length() - i;

                int ans = 0;
                if(a[i] == b[j]){
                    ans =  next[j+1];
                }
                else {
                    int insertAns = 1 + curr[j+1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1 + next[j+1];
                    ans = min(insertAns, min(deleteAns,replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        // return solve(word1, word2, 0, 0);
        int n= word1.length();
        int m = word2.length();
        if(n == 0) return m;
        if(m == 0) return n;
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveMemo(word1, word2, 0, 0, dp);

        // return solveTab(word1, word2);
        return solveTabSO(word1, word2);

    }
};