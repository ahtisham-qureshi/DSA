class Solution {
    vector<int> dp;
    int INVAL = 1e9;
public:
    int numSquares(int n) {
        int m = sqrt(n);
        dp.assign(n + 1, INVAL);
        
        dp[0] = 0;
        
        for (int i = 1; i <= m; i++) {
            vector<int> curr(n+1,INVAL);
            curr[0] = 0;
            for (int j = 1; j <= n; j++) {
                int skip = dp[j];
                int take = INVAL;
                if (j >= i * i)
                    take = 1 + curr[j - (i * i)];

                curr[j] = min(skip, take);
            }
            dp = curr;
        }

        return dp[n];
    }
};
