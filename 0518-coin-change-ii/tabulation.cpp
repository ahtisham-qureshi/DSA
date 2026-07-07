class Solution {
    vector<vector<unsigned long long>> dp;

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n, vector<unsigned long long>(amount + 1, 0));

        for(int i = 0;i<n;i++) dp[i][0] = 1;
        for(int i = coins[0];i<=amount;i += coins[0]) dp[0][i] = 1;

        for(int i = 1;i<n;i++){
            for(int target = 1;target<=amount;target++){
                unsigned long long skip = dp[i - 1][target];
                unsigned long long take = 0;
                if (coins[i] <= target)
                    take = dp[i][target - coins[i]];

                dp[i][target] = skip + take;
            }
        }


        return (int)dp[n-1][amount];
    }
};
