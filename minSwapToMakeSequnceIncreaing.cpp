class Solution {
public:
// TC O(2^n)
    int solveByRec(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
        if(index == nums1.size()) return 0;

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped) {
            swap(prev1, prev2);
        }
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveByRec(nums1, nums2, index+1, 0);
        if(nums1[index]> prev2 && nums2[index] > prev1){
            ans = min(ans, 1+ solveByRec(nums1, nums2, index+1, 1));
        }
        return ans;
    }
    // Tc O(n*n) Sc O(n*n)
int solveByMemo(vector<int>& nums1, vector<int>& nums2, int index, bool swapped,vector<vector<int>> &dp) {
        if(index == nums1.size()) return 0;

        if(dp[index][swapped] != -1) {
            return dp[index][swapped];
        }
        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped) {
            swap(prev1, prev2);
        }
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveByMemo(nums1, nums2, index+1, 0, dp);
        if(nums1[index]> prev2 && nums2[index] > prev1){
            ans = min(ans, 1+ solveByMemo(nums1, nums2, index+1, 1, dp));
        }
        dp[index][swapped] = ans;
        return dp[index][swapped];
    }
// SO O(1) Tc (n)
int solveByTabSO(vector<int>& nums1, vector<int>& nums2){
    int n= nums1.size();
    int swap =0;
    int noswap = 0;
    int currswap =0;
    int currnoswap = 0;
    
    for(int index = n-1; index >=1; index--){
        for(int swapped = 1; swapped>=0; swapped--){
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            if(swapped) {
                int temp = prev1;
                prev1= prev2;
                prev2 = temp;
                // swap(prev1, prev2);
            }
            if(nums1[index] > prev1 && nums2[index] > prev2)
                ans = noswap;
            if(nums1[index]> prev2 && nums2[index] > prev1){
                    ans = min(ans, 1+ swap);
            }
            if(swapped){
                currswap = ans;
            }else {
                currnoswap = ans;
            }
        }
        swap = currswap;
        noswap = currnoswap;
    }
    return min(swap, noswap);

}
// TC O(n) Sc(n)
int solveByTab(vector<int>& nums1, vector<int>& nums2){
    int n= nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int index = n-1; index >=1; index--){
        for(int swapped = 1; swapped>=0; swapped--){
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            if(swapped) {
                swap(prev1, prev2);
            }
            if(nums1[index] > prev1 && nums2[index] > prev2)
                ans = dp[index+1][0];
            if(nums1[index]> prev2 && nums2[index] > prev1){
                    ans = min(ans, 1+ dp[index+1][1]);
            }
            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];

}


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        bool swapped = 0;
        // return solveByRec(nums1, nums2, 1, swapped);
        int n = nums1.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solveByMemo(nums1, nums2, 1, swapped, dp);
        // return solveByTab(nums1, nums2);
        return solveByTabSO(nums1, nums2);

    }
};