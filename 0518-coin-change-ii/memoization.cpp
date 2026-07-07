class Solution {
    vector<vector<int>> dp;

public:
    int solve(int i, int target, vector<int>& coins) {
        if (target == 0)
            return 1;
        if (i == 0)
            return target % coins[0] == 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int skip = solve(i - 1, target, coins);
        int take = 0;
        if (coins[i] <= target)
            take = solve(i, target - coins[i], coins);

        return dp[i][target] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins);
    }
};
