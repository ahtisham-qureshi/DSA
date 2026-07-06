class Solution {
    const int INF = 1e9;
    vector<int> dp;

public:
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount + 1, INF);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int best = INF;
            
            for (int coin : coins)
                if(i>= coin)
                    best = min(best, dp[i - coin]);

            if (best != INF)
                dp[i] = 1 + best;
        }


        return dp[amount] == INF ? -1 : dp[amount];
    }
};