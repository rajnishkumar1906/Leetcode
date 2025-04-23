class Solution {  
public:  
    int ways(int i, int n, vector<int>& dp) {  
        if (i > n) return 0;    
        if (i == n) return 1;  
        if (dp[i] != -1) return dp[i];   
        dp[i] = ways(i + 1, n, dp) + ways(i + 2, n, dp);  
        return dp[i];  
    }  
    
    int climbStairs(int n) {  
        vector<int> dp(n + 1, -1);  
        return ways(0, n, dp);  
    }  
};  