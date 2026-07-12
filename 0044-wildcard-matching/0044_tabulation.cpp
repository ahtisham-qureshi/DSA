class Solution {
    vector<vector<bool>> dp;
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        dp.assign(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int k = 1; k <= n; k++) {
            if (dp[0][k - 1] && p[k-1] == '*')
                dp[0][k] = true;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else
                    dp[i][j] = 0;
            }
        }

        return dp[m][n];
    }
};
