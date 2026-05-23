class Solution {
public:
    int soleByRecursion(vector<int> &obs, int curLane, int curPos) {
        int n = obs.size()-1;
        if (curPos == n) return 0;
        if(obs[curPos+1] != curLane) {
            return soleByRecursion(obs, curLane, curPos+1);
        }
        else {
            int ans = INT_MAX;
            for(int i=1; i<=3; i++) {
                if(curLane != i && obs[curPos] != i) {
                    ans = min(ans, 1 + soleByRecursion(obs, i, curPos));
                }
            }
            return ans;
        }
    }
    int soleByMemoization(vector<int> &obs, int curLane, int curPos, vector<vector<int>> &dp) {
        int n = obs.size()-1;
        if (curPos == n) return 0;
        if(dp[curLane][curPos] != -1) return dp[curLane][curPos];
        if(obs[curPos+1] != curLane) {
            return soleByMemoization(obs, curLane, curPos+1, dp);
        }
        else {
            int ans = INT_MAX;
            for(int i=1; i<=3; i++) {
                if(curLane != i && obs[curPos] != i) {
                    ans = min(ans, 1 + soleByMemoization(obs, i, curPos, dp));
                }
            }
            dp[curLane][curPos] = ans;
            return dp[curLane][curPos];
        }
    }

// TC O(4*n) SC O(4*n)
    int solveByTabulation(vector<int> &obs) {
        vector<vector<int>> dp(4, vector<int> (obs.size(), 1e9));
        int n = obs.size()-1;
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int curPos = n-1; curPos>=0; curPos--) {
            for(int curLane =1; curLane<=3; curLane++){
                if(obs[curPos+1] != curLane) {
                    dp[curLane][curPos] =  dp[curLane][curPos+1];
                }
                else {
                    int ans = 1e9;
                    for(int i=1; i<=3; i++) {
                        if(curLane != i && obs[curPos] != i) {
                            ans = min(ans, 1 + dp[i][curPos+1]);
                        }
                    }
                    dp[curLane][curPos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }

    int solveByTabulationSO(vector<int> &obs) {
        vector<int> curr(4, INT_MAX);
        vector<int> next(4,INT_MAX);
        int n = obs.size()-1;
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int curPos = n-1; curPos>=0; curPos--) {
            for(int curLane =1; curLane<=3; curLane++){
                if(obs[curPos+1] != curLane) {
                    curr[curLane] =  next[curLane];
                }
                else {
                    int ans = 1e9;
                    for(int i=1; i<=3; i++) {
                        if(curLane != i && obs[curPos] != i) {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[curLane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        // return soleByRecursion(obstacles, 2, 0);

        // vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1));
        // return soleByMemoization(obstacles, 2, 0, dp);

        // return solveByTabulation(obstacles);
        return solveByTabulationSO(obstacles);

    }
};