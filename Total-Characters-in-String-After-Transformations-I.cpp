class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> dp;

    long long dfs(char ch, int t) {
        int idx = ch - 'a';

        if (dp[idx][t] != -1) return dp[idx][t];

        if (t == 0) return 1; // No further change

        if (ch == 'z') {
            // 'z' becomes "ab"
            long long res = (dfs('a', t - 1) + dfs('b', t - 1)) % MOD;
            return dp[idx][t] = res;
        } else {
            // Next char
            long long res = dfs(ch + 1, t - 1) % MOD;
            return dp[idx][t] = res;
        }
    }

    int lengthAfterTransformations(string s, int T) {
        dp.assign(26, vector<long long>(T + 1, -1));
        long long totalChars = 0;
        for (char ch : s) {
            totalChars = (totalChars + dfs(ch, T)) % MOD;
        }
        return (int)totalChars;
    }
};