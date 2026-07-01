class Solution {
    int MOD = 1e9 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        for (int i = high; i >= 0; i--) {
            int ans = (i >= low);
            if (i + zero <= high)
                ans = (ans + dp[i + zero]) % MOD;
            if (i + one <= high)
                ans = (ans + dp[i + one]) % MOD;

            dp[i] = ans;
        }

        return dp[0];
    }
};