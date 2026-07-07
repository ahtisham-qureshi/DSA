class Solution {
    vector<vector<int>> dp;
    int INVAL = 1e9;

public:
    int solve(int i, int n) {
        if (n == 0)
            return 0;
        if (i == 0)
            return INVAL;

        if (dp[i][n] != -1)
            return dp[i][n];

        int skip = solve(i - 1, n);
        int take = INVAL;
        if (n >= i * i)
            take = 1 + solve(i, n - (i * i));

        return dp[i][n] = min(skip, take);
    }
    int numSquares(int n) {
        int m = sqrt(n);
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return solve(m, n);
    }
};