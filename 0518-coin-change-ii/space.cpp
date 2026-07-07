class Solution {
    vector<unsigned long long> dp;

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(amount + 1, 0);

        dp[0] = 1;
        for(int i = coins[0];i<=amount;i += coins[0]) dp[i] = 1;

        for(int i = 1;i<n;i++){
            vector<unsigned long long> curr(amount+1,0);
            curr[0] = 1;
            for(int target = 1;target<=amount;target++){
                unsigned long long skip = dp[target];
                unsigned long long take = 0;
                if (coins[i] <= target)
                    take = curr[target - coins[i]];

                curr[target] = skip + take;
            }
            dp = curr;
        }


        return (int)dp[amount];
    }
};
