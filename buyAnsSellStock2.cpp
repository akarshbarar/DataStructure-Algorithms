class Solution {
public:
    int solveByRec(int index, int buy, vector<int> &prices) {
        if(index == prices.size()) return 0;
        int profit = 0;
        if(buy) {
            int buyKro = -prices[index] + solveByRec(index+1, 0, prices);
            int skipKro = solveByRec(index+1, 1, prices);
            profit = max(buyKro, skipKro);
        }
        else {
            int sellKro = prices[index] + solveByRec(index+1, 1, prices);
            int skipKro = solveByRec(index+1, 0, prices);

            profit = max(sellKro, skipKro);
        }
        return profit;
    }
    int solveByMemo(int index, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        if(index == prices.size()) return 0;
        int profit = 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy) {
            int buyKro = -prices[index] + solveByMemo(index+1, 0, prices, dp);
            int skipKro = solveByMemo(index+1, 1, prices, dp);
            profit = max(buyKro, skipKro);
        }
        else {
            int sellKro = prices[index] + solveByMemo(index+1, 1, prices, dp);
            int skipKro = solveByMemo(index+1, 0, prices, dp);

            profit = max(sellKro, skipKro);
        }
        return dp[index][buy]=profit;
    }
    int solveByTab(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        for(int index= n-1; index>=0;index--) {
            for(int buy = 0; buy <=1; buy++) {
                int profit = 0;
                if(buy) {
                    int buyKro = -prices[index] + dp[index+1][0];
                    int skipKro = dp[index+1][1];;
                    profit = max(buyKro, skipKro);
                }
                else {
                    int sellKro = prices[index] + dp[index+1][1];
                    int skipKro = dp[index+1][0];

                    profit = max(sellKro, skipKro);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
    // Tc O(2n) sc O(2n)
    int solveByTabSO(vector<int> &prices) {
        int n = prices.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        for(int index= n-1; index>=0;index--) {
            for(int buy = 0; buy <=1; buy++) {
                int profit = 0;
                if(buy) {
                    int buyKro = -prices[index] + next[0];
                    int skipKro = next[1];;
                    profit = max(buyKro, skipKro);
                }
                else {
                    int sellKro = prices[index] + next[1];
                    int skipKro = next[0];

                    profit = max(sellKro, skipKro);
                }
                curr[buy]=profit;
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        // return solveByRec(0, 1, prices);
        // int n= prices.size();
        // vector<vector<int>> dp(n+1, vector<int> (2,-1));
        // return solveByMemo(0, 1, prices, dp);
        // return solveByTab(prices);
        return solveByTabSO(prices);

    }
};