class Solution {
public:
    int func(int idx, int n, int sum, vector<int>& nums, int target, vector<vector<int>>& memo, int offset) {
        if (idx == n) {
            return sum == target ? 1 : 0;
        }

        if (memo[idx][sum + offset] != -1) 
            return memo[idx][sum + offset];

        int include = func(idx + 1, n, sum + nums[idx], nums, target, memo, offset);
        int exclude = func(idx + 1, n, sum - nums[idx], nums, target, memo, offset);

        return memo[idx][sum + offset] = include + exclude;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        // Offset for negative sums
        int offset = totalSum;  
        
        vector<vector<int>> memo(n, vector<int>(2 * totalSum + 1, -1));

        return func(0, n, 0, nums, target, memo, offset);
    }
};
