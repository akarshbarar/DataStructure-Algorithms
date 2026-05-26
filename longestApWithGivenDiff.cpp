class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int ans = 0;
        unordered_map<int,int> dp;
        for(int i=0; i< arr.size(); i++) {
            int currDiff = arr[i] - diff;
            int currAns = 0;
            if(dp.count(diff)) {
                currAns = dp[currDiff];
            }
            dp[arr[i]] = 1 + dp[currDiff];
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};