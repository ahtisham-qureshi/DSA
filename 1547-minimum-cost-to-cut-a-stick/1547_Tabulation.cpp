class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int N = cuts.size();
         vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i = N - 2; i >= 1; i--) {
            for (int j = i; j <= N - 2; j++) {
                int ans = 1e9;
                for (int k = i; k <= j; k++) {
                    int temp = cuts[j + 1] - cuts[i - 1] +
                               dp[i][k-1] + dp[k+1][j];
                    ans = min(ans, temp);
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][N-2];
    }
};
