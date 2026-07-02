class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(n);

        dp = grid[n-1];

        for(int i = n - 2;i>=0;i--){
            vector<int> curr(n);
            for(int j = 0;j<n;j++){
                int best = 1e9;
                for(int k = 0;k<n;k++){
                    if(k == j) continue;
                    best = min(best,dp[k]);
                }
                curr[j] = grid[i][j] + best;
            }
            dp = curr;
        }

        int ans = 1e9;
        for(int i = 0;i<n;i++) {
            ans = min(ans,dp[i]);
        }

        return ans;
    }
};
