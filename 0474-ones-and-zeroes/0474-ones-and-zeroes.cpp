class Solution {
public:
    int countCh(char ch, string &str) {
        int count = 0;
        for (char c : str) {
            if (c == ch) {
                count++;
            }
        }
        return count;
    }

    int solve(int i, int N, int m, int n, vector<string>& strs, vector<vector<vector<int>>>& dp) {
        if (i >= N) {
            return 0;
        }
        if (m < 0 || n < 0) {
            return 0;
        }
        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        int zero = countCh('0', strs[i]);
        int one = countCh('1', strs[i]);

        int notPick = solve(i + 1, N, m, n, strs, dp);

        int pick = 0;
        if (m - zero >= 0 && n - one >= 0) {
            pick = 1 + solve(i + 1, N, m - zero, n - one, strs, dp);
        }

        return dp[i][m][n] = max(pick, notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(0, N, m, n, strs, dp);
    }
};