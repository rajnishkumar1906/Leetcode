class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i >= nums.size()) return false;
        if (dp[i][target] != -1) return dp[i][target];
        if (nums[i] > target) {
            return dp[i][target] = solve(i + 1, target, nums, dp);
        }
        bool inclusion = solve(i + 1, target - nums[i], nums, dp);
        bool exclusion = solve(i + 1, target, nums, dp);
        return dp[i][target] = inclusion || exclusion;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(0, target, nums, dp);
    }
};
