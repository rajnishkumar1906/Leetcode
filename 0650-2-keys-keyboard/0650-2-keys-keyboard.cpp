class Solution {
public:
    int solve(int n, int cpd, int avl, vector<vector<int>>& dp) {
        if (avl == n) return 0;          
        if (avl > n) return INT_MAX / 2; 

        if (dp[avl][cpd] != -1) return dp[avl][cpd];

        int ans = INT_MAX / 2;

        if (cpd != avl) {
            ans = min(ans, 1 + solve(n, avl, avl, dp));
        }

        if (cpd > 0) {
            ans = min(ans, 1 + solve(n, cpd, avl + cpd, dp));
        }

        return dp[avl][cpd] = ans;
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, 0, 1, dp); 
    }
};
