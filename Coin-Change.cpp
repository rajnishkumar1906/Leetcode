class Solution {  
public:  
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {  
        if (amount == 0) return 0;  
        if (amount < 0) return INT_MAX;  
        if (i >= coins.size()) return INT_MAX;  

        if (dp[i][amount] != -1) return dp[i][amount];  

        int includeCurrent = solve(i, coins, amount - coins[i], dp);  
        int excludeCurrent = solve(i + 1, coins, amount, dp);  

        if (includeCurrent != INT_MAX) {  
            includeCurrent += 1;  
        }  

        dp[i][amount] = min(includeCurrent, excludeCurrent);  
        return dp[i][amount];  
    }  

    int coinChange(vector<int>& coins, int amount) {  
        int n = coins.size();  
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));  
        int result = solve(0, coins, amount, dp);  
        return result == INT_MAX ? -1 : result;  
    }  
};  