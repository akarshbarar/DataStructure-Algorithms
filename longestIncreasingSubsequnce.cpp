class Solution {
  public:
    int solveByRecursion(int n, vector<int> &arr, int currIndex, int prevIndex) {
        if (currIndex == n)  return 0;
        int include = 0;
        if (prevIndex == -1 || arr[currIndex] > arr[prevIndex]) {
            include = 1 + solveByRecursion(n, arr, currIndex+1, currIndex);
        }
        int exclude = solveByRecursion(n, arr, currIndex+1, prevIndex);
        int ans = max(include, exclude);
        return ans;
    }
    
    int solveByMemo(int n, vector<int> &arr, int currIndex, int prevIndex, vector<vector<int>> &dp) {
        if (currIndex == n)  return 0;
        if(dp[currIndex][prevIndex+1] != -1) return dp[currIndex][prevIndex+1];
        int include = 0;
        if (prevIndex == -1 || arr[currIndex] > arr[prevIndex]) {
            include = 1 + solveByMemo(n, arr, currIndex+1, currIndex, dp);
        }
        int exclude = solveByMemo(n, arr, currIndex+1, prevIndex, dp);
        dp[currIndex][prevIndex+1] = max(include, exclude);
        return dp[currIndex][prevIndex+1];
    }
    // TC O(n*n) Sc O(n*n)
    int solveByTab(int n, vector<int> &arr) {

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
        for(int currIndex = n-1; currIndex >= 0; currIndex--) {
    
            for(int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--) {
    
                int include = 0;
    
                if(prevIndex == -1 || arr[currIndex] > arr[prevIndex]) {
                    include = 1 + dp[currIndex+1][currIndex+1];
                }
    
                int exclude = dp[currIndex+1][prevIndex+1];
    
                dp[currIndex][prevIndex+1] = max(include, exclude);
            }
        }
    
        return dp[0][0];
    }
    
    // TC O(n*n) SC O(n)
    int solveByTabSO(int n, vector<int> &arr) {

        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        for(int currIndex = n-1; currIndex >= 0; currIndex--) {
    
            for(int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--) {
    
                int include = 0;
    
                if(prevIndex == -1 || arr[currIndex] > arr[prevIndex]) {
                    include = 1 + nextRow[currIndex+1];
                }
    
                int exclude = nextRow[prevIndex+1];
    
                currRow[prevIndex+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
    
        return nextRow[0];
    }
    
    int solveOptimal(int n, vector<int> & arr) {
        if(n == 0) return 0;
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1; i<n; i++) {
            if(arr[i] > ans.back()) {
                ans.push_back(arr[i]);
            }
            else {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        
        return ans.size();
    }
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        // return solveByRecursion(n, arr, 0, -1);
        
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solveByMemo(n, arr, 0, -1, dp);
        
        // return solveByTab(n, arr);
        
        // return solveByTabSO(n, arr);
                return solveOptimal(n, arr);

    }
};