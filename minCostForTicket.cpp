int solveByRecursion(int n, vector<int> &days, vector<int> &cost, int index)
{
    // Base Case
    if(index >=n) return 0;
    // DAy 1 Pass
    int option1 = cost[0] + solveByRecursion(n, days, cost, index +1);
    int i;
    // Day 7 Pass
    for(i = index; i<n && days[i]< days[index] + 7; i++);
    int option2 = cost[1] + solveByRecursion(n, days, cost, i);
    // Daty 30 pass
    for(i = index; i<n && days[i]< days[index] + 30; i++);
    int option3 = cost[2] + solveByRecursion(n, days, cost, i);
    int ans= min(option1, min(option2, option3));
    return ans;
}
int solveByMemoization(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    // Base Case
    if(index >=n) return 0;
    if(dp[index] != -1) return dp[index];
    // DAy 1 Pass
    int option1 = cost[0] + solveByMemoization(n, days, cost, index +1, dp);
    int i;
    // Day 7 Pass
    for(i = index; i<n && days[i]< days[index] + 7; i++);
    int option2 = cost[1] + solveByMemoization(n, days, cost, i, dp);
    // Daty 30 pass
    for(i = index; i<n && days[i]< days[index] + 30; i++);
    int option3 = cost[2] + solveByMemoization(n, days, cost, i, dp);
    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

int solveByTabulation(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
    for(int k=n-1; k>=0; k--) {
        int option1 = cost[0] + dp[k+1];
        int i;
        for(i = k; i<n && days[i]< days[k] + 7; i++);
        int option2 = cost[1] + dp[i];
        for(i = k; i<n && days[i]< days[k] + 30; i++);
        int option3 = cost[2] + dp[i];
        dp[k] = min(option1, min(option2, option3));

    } 
    return dp[0];
}
int solveByQueue(int n, vector<int> & days, vector<int> &cost) {
    int ans = 0;
    queue<pair<int, int>> monthly;
    queue<pair<int,int>> weekly;
    for(int day: days) {
        while(!monthly.empty() && monthly.front().first + 30 <=day){
            monthly.pop();
        }
        while(!weekly.empty() && weekly.front().first + 7 <=day){
            weekly.pop();
        }
        weekly.push(make_pair(day, ans+cost[1]));
        monthly.push(make_pair(day, ans+cost[2]));
        ans = min(ans+cost[0], min(monthly.front().second, weekly.front().second));
    }

    return ans;
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    // return solveByRecursion(n,days, cost, 0);

    // vector<int> dp(n+1, -1);
    // return solveByMemoization(n, days, cost, 0, dp);

    // return solveByTabulation(n, days, cost);
        return solveByQueue(n, days, cost);

}