//! 46. Permutations
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index ) {
        if (index >= nums.size()) {
            ans.push_back(nums);
        }
        for(int i = index; i<nums.size(); i++) {
            swap(nums[i], nums[index]);
            solve(nums, ans, index+1);
            // Backtraking
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};