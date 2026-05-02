#define MOD 1000000007
#include<vector>

long long int solve(int n, vector<long long int> &dp) {
    // Write your code here.

    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n]= ( ((n-1)%MOD) * ((solve(n-1, dp)%MOD)
                            + (solve(n-2, dp)%MOD) )%MOD );
    return dp[n];
}


long long int solveTab(int n) {
    // Write your code here.

    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++) {
        dp[i]= ( ((i-1)%MOD) * ((dp[i-1]%MOD) + (dp[i-2]%MOD) )%MOD );
    }
    
    return dp[n];
}

long long int solveTabSimpify(int n) {
    // Write your code here.
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i=3; i<=n; i++) {
        long long int ans= ( ((i-1)%MOD) * ((prev1%MOD) + (prev2%MOD) )%MOD );
        prev2 = prev1;
        prev1 = ans;
    }

    
    return prev1;
}

long long int countDerangements(int n) {
    // Write your code here.

    // REcursion Tc O(n^x)
    // if(n==1) return 0;
    // if(n==2) return 1;

    // int ans = ( ((n-1)%MOD) * ((countDerangements(n-1)%MOD)
    //                         + (countDerangements(n-2)%MOD) )%MOD );
    // return ans;

    // Rec + memo Tc O(N) Sc O(N)+ O(N)
    // vector<long long int> dp(n+1, -1);
    // return solve(n, dp);


    // Tabulation Tc O(N) Sc O(N)
    // return solveTab(n);

    // tabulation Tc I(N) Sc O(1)
    return solveTabSimpify(n);


}