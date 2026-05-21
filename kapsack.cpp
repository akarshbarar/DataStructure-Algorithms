#include <bits/stdc++.h> 

int solve(vector<int> weight, vector<int> value, int index, int capacity) 
{
	// BaseCase
	// if only 1 item is left then add it into bag if capit is there otherwise add 0
	if (index == 0 ) {
		if(weight[0] <= capacity) {
			return value[0];
		}
		else {
			return 0;
		}
	}
	int include = 0;
	if (weight[index] <= capacity) 
		include = value[index]+solve(weight, value, index-1, capacity-weight[index]);
	
	int exclude = solve(weight, value, index-1, capacity);
	int ans = max(include, exclude);
	return ans;

}

int solveMemo(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>> &dp) 
{
	// BaseCase
	// if only 1 item is left then add it into bag if capit is there otherwise add 0
	if (index == 0 ) {
		if(weight[0] <= capacity) {
			return value[0];
		}
		else {
			return 0;
		}
	}
	if (dp[index][capacity] != -1)
		return dp[index][capacity];

	int include = 0;
	if (weight[index] <= capacity) 
		include = value[index]+solveMemo(weight, value, index-1, capacity-weight[index], dp);
	
	int exclude = solveMemo(weight, value, index-1, capacity, dp);
	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];

}

int solveTab(vector<int> weight, vector<int> value, int n, int capacity) 
{
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    // Initialization
    for(int w = 0; w <= capacity; w++) {
        if(weight[0] <= w) {
            dp[0][w] = value[0];
        }
        else {
            dp[0][w] = 0;
        }
    }

    // Build DP
    for(int index = 1; index < n; index++) {
        for(int w = 0; w <= capacity; w++) {

            int include = 0;

            if(weight[index] <= w) 
                include = value[index] + dp[index-1][w - weight[index]];
            
            int exclude = dp[index-1][w];

            dp[index][w] = max(include, exclude);
        }
    }

    return dp[n-1][capacity];
}

int solveTabSpaceOptimization(vector<int> weight, vector<int> value, int n, int capacity) 
{
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);
    // Initialization
    for(int w = 0; w <= capacity; w++) {
        if(weight[0] <= w) {
            prev[w] = value[0];
        }
        else {
            prev[w] = 0;
        }
    }

    // Build DP
    for(int index = 1; index < n; index++) {
        for(int w = 0; w <= capacity; w++) {

            int include = 0;

            if(weight[index] <= w) 
                include = value[index] + prev[w - weight[index]];
            
            int exclude = prev[w];

            curr[w] = max(include, exclude);
        }
		prev = curr;
    }

    return prev[capacity];
}
int solveTabSpaceOptimizationMore(vector<int> weight, vector<int> value, int n, int capacity) 
{
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);
    // Initialization
    for(int w = 0; w <= capacity; w++) {
        if(weight[0] <= w) {
            curr[w] = value[0];
        }
        else {
            curr[w] = 0;
        }
    }

    // Build DP
    for(int index = 1; index < n; index++) {
        for(int w = capacity; w >=0; w--) {

            int include = 0;

            if(weight[index] <= w) 
                include = value[index] + curr[w - weight[index]];
            
            int exclude = curr[w];

            curr[w] = max(include, exclude);
        }
    }

    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// Recursion
	// return solve(weight, value, n-1, maxWeight);

	// Recursion + memoization
	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return solveMemo(weight, value, n-1, maxWeight, dp);

	// Tabulation
	// return solveTab(weight, value, n, maxWeight);

	// Tab + space optimzation
// return solveTabSpaceOptimization(weight, value, n, maxWeight);
return solveTabSpaceOptimizationMore(weight, value, n, maxWeight);

}