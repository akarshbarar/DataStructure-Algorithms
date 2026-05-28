class Solution {
public:
    int solveByRec(int index, int buy, vector<int> &prices, int limit) {
        if(index == prices.size()) return 0;
        if(limit == 0) return 0;
        int profit = 0;
        if(buy) {
            int buyKro = -prices[index] + solveByRec(index+1, 0, prices, limit);
            int skipKro = solveByRec(index+1, 1, prices, limit);
            profit = max(buyKro, skipKro);
        }
        else {
            int sellKro = prices[index] + solveByRec(index+1, 1, prices, limit-1);
            int skipKro = solveByRec(index+1, 0, prices, limit);

            profit = max(sellKro, skipKro);
        }
        return profit;
    }
    int solveByMemo(int index, int buy, vector<int> &prices,int limit, vector<vector<vector<int>>> &dp) {
        if(index == prices.size()) return 0;
        if(limit == 0) return 0;
        int profit = 0;
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
        if(buy) {
            int buyKro = -prices[index] + solveByMemo(index+1, 0, prices, limit,dp);
            int skipKro = solveByMemo(index+1, 1, prices, limit, dp);
            profit = max(buyKro, skipKro);
        }
        else {
            int sellKro = prices[index] + solveByMemo(index+1, 1, prices,limit-1, dp);
            int skipKro = solveByMemo(index+1, 0,prices,limit, dp);

            profit = max(sellKro, skipKro);
        }
        return dp[index][buy][limit]=profit;
    }
    int solveByTab(vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2,vector<int> (3, 0)));

        // vector<vector<int>> dp(n+1, vector<int> (2,0));
        for(int index= n-1; index>=0;index--) {
            for(int buy = 0; buy <=1; buy++) {
                for(int limit = 1;limit<=2; limit++) {
                    int profit = 0;
                    if(buy) {
                        int buyKro = -prices[index] + dp[index+1][0][limit];
                        int skipKro = dp[index+1][1][limit];
                        profit = max(buyKro, skipKro);
                    }
                    else {
                        int sellKro = prices[index] + dp[index+1][1][limit-1];
                        int skipKro = dp[index+1][0][limit];

                        profit = max(sellKro, skipKro);
                    }
                    dp[index][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
    // Tc O(2n) sc O(1)
    int solveByTabSO(vector<int> &prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2,vector<int> (3, 0)));

        vector<vector<int>> curr(2, vector<int> (3, 0));
        vector<vector<int>> next(2, vector<int> (3, 0));
        for(int index= n-1; index>=0;index--) {
            for(int buy = 0; buy <=1; buy++) {
                for(int limit = 1; limit<=2; limit ++) {
                    int profit = 0;
                    if(buy) {
                        int buyKro = -prices[index] + next[0][limit];
                        int skipKro = next[1][limit];
                        profit = max(buyKro, skipKro);
                    }
                    else {
                        int sellKro = prices[index] + next[1][limit-1];
                        int skipKro = next[0][limit];

                        profit = max(sellKro, skipKro);
                    }
                    curr[buy][limit]=profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int>& prices) {
        int limit = 2;
        // return solveByRec(0, 1, prices, limit);
        // int n= prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2,vector<int> (3, -1)));
        // return solveByMemo(0, 1, prices,limit,  dp);
        // return solveByTab(prices);
        return solveByTabSO(prices);

    }
};