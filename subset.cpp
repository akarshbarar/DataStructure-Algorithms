//! 78. Subsets
// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
    void solve(vector<int>& nums,vector<int> output, int i,vector<vector<int>> &res  ) {
        if (i >= nums.size()) {
            res.push_back(output);
            return;
        }
        solve(nums, output, i+1, res);

        int ele = nums[i];
        output.push_back(ele);
        solve(nums, output, i+1, res);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> output;
            int i = 0;
            solve(nums, output, i, res);
            return res; 
        
    }
};