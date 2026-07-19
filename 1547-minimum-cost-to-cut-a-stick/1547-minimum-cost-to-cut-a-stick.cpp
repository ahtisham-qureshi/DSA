class Solution {
    vector<vector<int>> dp;

public:
    int solve(int i, int j, vector<int>& cuts) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;
        for (int k = i; k <=j; k++) {
            int temp = cuts[j + 1] - cuts[i - 1] + solve(i, k-1, cuts) +
                       solve(k + 1, j, cuts);
            ans = min(ans, temp);
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int N = cuts.size();
        dp.assign(N, vector<int>(N, -1));

        return solve(1, N - 2, cuts);
    }
};