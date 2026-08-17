class Solution {
    vector<vector<int>> dp;
    vector<int> prefix;

public:
    int solve(int i, int j, vector<int>& stoneValue) {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        for (int k = i; k < j; k++) {

            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];

            if (leftSum < rightSum) {
                ans = max(ans, leftSum + solve(i, k, stoneValue));
            }
            else if (rightSum < leftSum) {
                ans = max(ans, rightSum + solve(k + 1, j, stoneValue));
            }
            else {
                ans = max(ans,
                          leftSum + max(solve(i, k, stoneValue),
                                        solve(k + 1, j, stoneValue)));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, vector<int>(n, -1));
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};