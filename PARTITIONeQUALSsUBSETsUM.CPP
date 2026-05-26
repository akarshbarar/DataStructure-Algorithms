class Solution {
  public:
//   TC O(2^n)
    bool solveByRec(vector<int> &arr, int tar, int sum, int index){
        if(sum == tar) return true;
        
        if(sum >tar) return false;
        
        if(index >= arr.size()) return false;
        bool include = solveByRec(arr, tar, sum + arr[index], index+1);
        bool exclude = solveByRec(arr, tar, sum, index+1);
        bool ans = include || exclude;
        return ans;
        
    }
    // Tc (n*n) Sc O(n*n)
    bool solveByMemo(vector<int> &arr, int tar, int sum, int index, vector<vector<int>> &dp){
        if(sum == tar) return true;
        
        if(sum >tar) return false;
        
        if(index >= arr.size()) return false;
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        bool include = solveByMemo(arr, tar, sum + arr[index], index+1, dp);
        bool exclude = solveByMemo(arr, tar, sum, index+1, dp);
        
        dp[index][sum] = include or exclude;
        
        return dp[index][sum];
    }
    
bool solveByTab(vector<int> &arr, int target) {

    int n = arr.size();

    vector<vector<bool>> dp(n + 1,vector<bool>(target + 1, false));

    // Base Case:
    // target 0 is always possible
    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for(int index = n - 1; index >= 0; index--) {

        for(int tar = 1; tar <= target; tar++) {

            bool include = false;

            if(arr[index] <= tar)
                include = dp[index + 1][tar - arr[index]];

            bool exclude = dp[index + 1][tar];

            dp[index][tar] = include || exclude;
        }
    }

    return dp[0][target];
}
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        for(auto &a : arr) {
            sum += a;
        }
        if(sum%2 != 0) return false;
         
        // return solveByRec(arr, sum/2, 0, 0);
        
        int n = arr.size();
        int target = sum/2;
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return solveByMemo(arr, target, 0, 0, dp);
        
        return solveByTab(arr, target);
    }
};