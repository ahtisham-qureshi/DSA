class Solution {
    vector<unsigned long long> dp;

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(amount + 1, 0);

        dp[0] = 1;
        for(int i = coins[0];i<=amount;i += coins[0]) dp[i] = 1;

        for(int i = 1;i<n;i++){
            for(int target = coins[i];target<=amount;target++){
                dp[target] += dp[target - coins[i]];
            }
        }


        return (int)dp[amount];
    }
};