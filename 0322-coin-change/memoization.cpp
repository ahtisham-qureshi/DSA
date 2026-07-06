class Solution {
    const int INF = 1e9;
    vector<int> dp;

public:
    int solve(int target, vector<int>& coins) {
        if (target == 0) return 0;
        if (target < 0) return INF;

        if (dp[target] != -1)
            return dp[target];

        int best = INF;

        for (int coin : coins)
            best = min(best, solve(target - coin, coins));

        if (best == INF)
            return dp[target] = INF;

        return dp[target] = 1 + best;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount + 1, -1);
        int ans = solve(amount, coins);
        return ans == INF ? -1 : ans;
    }
};
