class Solution {
    const int INF = 1e9;
    vector<vector<int>> dp;

public:
    int solve(int i,int target, vector<int>& coins) {
        if (target < 0 || i<0) return INF;
        if (target == 0) return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int best = INF;

        int take = 1 + solve(i,target-coins[i],coins);
        int skip = solve(i-1,target,coins);

        return dp[i][target] = min(take,skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n,vector<int>(amount + 1, -1));
        int ans = solve(n-1,amount, coins);
        return ans == INF ? -1 : ans;
    }
};