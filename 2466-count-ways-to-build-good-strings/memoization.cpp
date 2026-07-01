class Solution {
    int MOD = 1e9 + 7;
public:
    int count(int i, int l, int h, int zero, int one, vector<int>& dp) {
        if (i > h)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = (i >= l);

        ans = (ans + count(i + zero, l, h, zero, one, dp)) % MOD;
        ans = (ans + count(i + one, l, h, zero, one, dp)) % MOD;

        return dp[i] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);

        return count(0, low, high, zero, one, dp);
    }
};
