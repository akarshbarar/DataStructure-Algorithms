#include <bits/stdc++.h> 
int solveByRecursion(vector<int> &num, int tar)
{
    // Base Case
    if (tar == 0 ) return 1;
    if (tar <0) return 0;
    int ans = 0;
    for(int i=0; i< num.size(); i++) {
        ans += solveByRecursion(num, tar - num[i]);
    }
    return ans;
}

int solveByMemoization(vector<int> &num, int tar,  vector<int> &dp)
{
    // Base Case
    if (tar == 0 ) return 1;
    if (tar <0) return 0;
    if (dp[tar] != -1) return dp[tar];
    int ans = 0;
    for(int i=0; i< num.size(); i++) {
        ans += solveByMemoization(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int solveByTabulation(vector<int> &num, int tar)
{
    vector<int> dp(tar+1, 0);
    dp[0] = 1;
    for(int i=1; i<=tar; i++) {
        for(int j=0; j< num.size(); j++ ) {
            if(i-num[j]>=0) 
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[tar];

}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // return solveByRecursion(num,tar);

    // vector<int> dp(tar+1, -1);
    // return solveByMemoization(num,tar, dp);

    return solveByTabulation(num, tar);

}