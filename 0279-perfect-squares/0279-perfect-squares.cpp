class Solution {
    vector<vector<int>> dp;
    int INVAL = 1e9;
public:
    int numSquares(int n) {
        int m = sqrt(n);
        dp.assign(m + 1, vector<int>(n + 1, INVAL));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int skip = dp[i - 1][j];
                int take = INVAL;
                if (j >= i * i)
                    take = 1 + dp[i][j - (i * i)];

                dp[i][j] = min(skip, take);
            }
        }

        return dp[m][n];
    }
};