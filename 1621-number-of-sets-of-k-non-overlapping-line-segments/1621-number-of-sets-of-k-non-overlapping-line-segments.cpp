class Solution {
    int MOD = 1e9 + 7;
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            int sum = 0;
            for (int i = 1; i < n; i++) {

                sum = (sum + dp[i - 1][j - 1]) % MOD;

                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};