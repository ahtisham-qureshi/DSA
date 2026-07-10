class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // Compute LPS
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        int lps = dp[0][n - 1];
        return n - lps;
    }
};