#include<limits.h>
int solveRec(int n, int x, int y, int z) {
	// Base Case
	if (n == 0) return 0;
	if ( n < 0) return INT_MIN;

	int a = solveRec(n-x, x, y, z) + 1;
	int b = solveRec(n-y, x, y, z) + 1;
	int c = solveRec(n-z, x, y, z) + 1;
	int ans = max(a, max(b,c));
	return ans;

}

int solveMemo(int n, int x, int y, int z, vector<int> &dp) {
	// Base Case
	if (n == 0) return 0;
	if ( n < 0) return INT_MIN;
	if(dp[n] != -1) return dp[n];
	int a = solveMemo(n-x, x, y, z, dp) + 1;
	int b = solveMemo(n-y, x, y, z, dp) + 1;
	int c = solveMemo(n-z, x, y, z, dp) + 1;
	dp[n] = max(a, max(b,c));
	return dp[n];
}

int solveTab(int n, int x, int y, int z) {

	vector<int> dp(n+1, INT_MIN);
	dp[0] = 0;

	for(int i=1; i<=n; i++) {
		if(i-x >=0) 
			dp[i] = max(dp[i], dp[i-x]+1);
		if(i-y >=0) 
			dp[i] = max(dp[i], dp[i-y]+1);
		if(i-z >=0) 
			dp[i] = max(dp[i], dp[i-z]+1);
	}

	return dp[n];
}


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// Recursion
	// int ans = solveRec(n,x,y,z);
	// if(ans < 0) return 0;
	// else return ans;

	// Rec + Memoization
	// vector<int> dp(n+1, -1);
	// int ans = solveMemo(n,x,y,z,dp);
	// if (ans < 0) return 0;
	// else return ans;

	// Tabulization
	int ans = solveTab(n,x,y,z);
	if (ans < 0) return 0;
	else return ans;
}