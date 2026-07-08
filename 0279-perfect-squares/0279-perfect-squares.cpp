class Solution {
    vector<int> dp;
    int INVAL = 1e9;
public:
    int numSquares(int n) {
        int m = sqrt(n);
        dp.assign(n + 1, INVAL);
        
        dp[0] = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = i*i; j <= n; j++) {
                dp[j] = min(dp[j], 1 + dp[j - (i * i)]);
            }
        }

        return dp[n];
    }
};